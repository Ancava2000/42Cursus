/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:15:42 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/17 13:31:57 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check if the path is accesible and if we have all the permissions.
static int	command_executable(t_command *cmd, char *cmd_path)
{
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->command_name[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free(cmd_path);
		return (126);
	}
	return (0);
}

// Configures the signals in the child proces.
static void	setup_child_io_and_signals(t_command *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	check_redir(cmd);
}

// In this functions the child process excute the command.
static void	execute_child_process(t_mini *mini, t_command *cmd, char *cmd_path)
{
	setup_child_io_and_signals(cmd);
	if (execve(cmd_path, cmd->command_name, mini->envp) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->command_name[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free(cmd_path);
		exit(127);
	}
}

//This function parent waits til' the execution finish, and return the signal.
static int	wait_for_child(pid_t pid, t_command *cmd)
{
	int	status;

	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, ctrl_quit);
	waitpid(pid, &status, 0);
	cmd->pid = pid;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	//else if (WIFSIGNALED(status))
	//	return (128 + WTERMSIG(status));
	return (1);
}

//Main function wich manages al the auxiliars ones.
int	run_external(t_mini *mini, t_command *cmd)
{
	pid_t	pid;
	char	*cmd_path;
	int		exec_status;

	cmd_path = path_handling(mini, cmd);
	exec_status = command_executable(cmd, cmd_path);
	if (exec_status != 0)
		return (exec_status);
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("minishell: fork failed\n", 2);
		free(cmd_path);
		return (1);
	}
	if (pid == 0)
		execute_child_process(mini, cmd, cmd_path);
	free(cmd_path);
	og_redir(mini, cmd);
	return (wait_for_child(pid, cmd));
}
