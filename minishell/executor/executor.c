/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:06:37 by kali              #+#    #+#             */
/*   Updated: 2025/08/05 14:21:28 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Hace falta hacer un wait_execute, para que cada
//proceso hijo o ejecución de comando se finalice correctamente

#include "../minishell.h"

int	execute_builtin(t_mini *mini, t_command *cmd)
{
	if (!ft_strncmp(cmd -> command_name[0], "echo", 5))
		return (mini_echo(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "cd", 3))
		return (run_cd(mini, cmd));
	else if (!ft_strncmp(cmd -> command_name[0], "pwd", 4))
		return (run_pwd(mini, cmd));
//	else if (!ft_strncmp(cmd -> command_name[0], "export", 7))
//		return (run_export(mini, cmd));
//	else if (!ft_strncmp(cmd -> command_name[0], "unset", 6))
//		return (run_unset(mini, cmd));
//	else if (!ft_strncmp(cmd -> command_name[0], "env", 4))
//		return (run_env(mini, cmd));
//	else if (!ft_strncmp(cmd -> command_name[0], "exit", 5))
//		return (run_exit(mini, cmd));
	return (1);
}

void	run_builtin(t_mini *mini, t_command *cmd)
{
	if (cmd -> infile != -2|| cmd -> outfile != -2)
	{
		check_redir(cmd);
		cmd -> exit_code = execute_builtin(mini, cmd);
		og_redir(mini, cmd);
	}
	else
		cmd -> exit_code = execute_builtin(mini, cmd);
}

void	run_cmd(t_mini *mini, t_command *cmd)
{
	if (!cmd -> command_name[0])
		cmd -> command_name[0] = ft_strdup("");
	if (!ft_strncmp(cmd -> command_name[0], "echo", 5)
		|| !ft_strncmp(cmd -> command_name[0], "cd", 3)
		|| !ft_strncmp(cmd -> command_name[0], "pwd", 4)
		|| !ft_strncmp(cmd -> command_name[0], "export", 7)
		|| !ft_strncmp(cmd -> command_name[0], "unset", 6)
		|| !ft_strncmp(cmd -> command_name[0], "env", 4)
		|| !ft_strncmp(cmd -> command_name[0], "exit", 5))
		run_builtin(mini, cmd);
//	else
//		run_external(mini, cmd);
}

void	wait_execute(t_mini *mini)
{
	t_command	*cmd;

	cmd = mini -> command_list;
	while(cmd)
	{
		mini -> exit_status = WEXITSTATUS(cmd -> exit_code);
		cmd = cmd -> next;
	}
}

void	execute(t_mini	*mini)
{
	int			fd[2];
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
