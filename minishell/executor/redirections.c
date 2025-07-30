/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:18:30 by kali              #+#    #+#             */
/*   Updated: 2025/07/26 08:22:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_redir(t_command *cmd)
{
	if (cmd -> infile != -2)
	{
		dup2(cmd -> infile, STDIN_FILENO);
		close(cmd -> infile);
	}
	if (cmd -> outfile != -2)
	{
		dup2(cmd -> outfile, STDOUT_FILENO);
		close(cmd -> outfile);
	}
}

void	og_redir(t_mini *mini, t_command *cmd)
{
	(void)cmd;
	dup2(mini -> og_infile, STDIN_FILENO);
	dup2(mini -> og_outfile, STDOUT_FILENO);
}
