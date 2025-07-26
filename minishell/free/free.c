/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:47:29 by kali              #+#    #+#             */
/*   Updated: 2025/07/26 14:53:34 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		free(str[i++]);
	if (str)
		free(str);
}

void	free_arrays(t_mini *mini)
{
	t_token		*tkn;
	t_command	*cmd;

	while (mini->token_list)
	{
		tkn = mini->token_list;
		mini->token_list = mini->token_list->next;
		free(tkn->token_name);
		free(tkn);
	}
	while (mini->command_list)
	{
		cmd = mini->command_list;
		mini->command_list = mini->command_list->next;
		free_split(cmd->command_name);
		free(cmd);
	}
}