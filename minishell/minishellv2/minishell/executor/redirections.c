/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:12:26 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/15 17:12:29 by emilgarc         ###   ########.fr       */
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
