/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:06:37 by kali              #+#    #+#             */
/*   Updated: 2025/07/23 15:31:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_mini *mini, t_command *cmd)
{
	if (!ft_strncmp(cmd -> command_name[0], "echo", 5))
		return (run_echo(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "cd", 3))
		return (run_cd(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "pwd", 4))
		return (run_pwd(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "export", 7))
		return (run_export(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "unset", 6))
		return (run_unset(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "env", 4))
		return (run_env(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "exit", 5))
		return (run_exit(mini, cmd));
	return (1);
}

void	run_builtin(t_mini *mini, t_command *cmd)
{
	if (cmd -> infile != STDIN_FILENO || cmd -> outfile != STDOUT_FILENO)
	{
		apply_redir(cmd);
		cmd -> exit_code = execute_builtin(mini, cmd);
		revert_redir(mini, cmd);
	}
	else
		cmd -> exit_code = execute_builtin(mini, cmd);
}

int	is_builtin(const char *command_name)
{
	if (!command_name)
		return (0);
	return (
		!ft_strncmp(command_name, "echo", 5) ||
		!ft_strncmp(command_name, "cd", 3) ||
		!ft_strncmp(command_name, "pwd", 4) ||
		!ft_strncmp(command_name, "export", 7) ||
		!ft_strncmp(command_name, "unset", 6) ||
		!ft_strncmp(command_name, "env", 4) ||
		!ft_strncmp(command_name, "exit", 5)
	);
}

void	run_cmd(t_mini *mini, t_command *cmd)
{
	if (!cmd -> command_name[0])
		cmd -> command_name[0] = ft_strdup("");
	if (is_builting(cmd -> command_name[0]))
		run_builting(mini, cmd);
	else
		run_external(mini, cmd);
}

void	execute(t_mini	*mini)
{
	int	fd[2];
	t_command	*cmd;

	cmd = mini -> command_list;
	while (cmd && cmd -> next)
	{
		if (pipe(fd) == -1)
			perror("Error creating pipe");
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		run_cmd(mini, cmd);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		cmd = cmd -> next;
	}
	if (cmd)
	{
		dup2(mini -> og_outfile, STDOUT_FILENO);
		run_cmd(mini, cmd);
		dup2(mini -> og_infile, STDIN_FILENO);
	}
	wait_execute(mini);
}
