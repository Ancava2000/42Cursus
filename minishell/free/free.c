/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:47:29 by kali              #+#    #+#             */
/*   Updated: 2025/07/30 13:54:57 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_commands(t_command *cmd)
{
	t_command	*cmd_aux;

	while (cmd)
	{
		cmd_aux = cmd;
		cmd = cmd -> next;
		if (cmd_aux -> command_name)
			free_array(cmd_aux -> command_name);
		free (cmd_aux);
	}
}

void	free_tokens(t_token *token)
{
	t_token	*token_aux;

	while (token)
	{
		token_aux = token;
		token = token -> next;
		if (token_aux -> token_name)
			free(token_aux -> token_name);
		free(token_aux);
	}
}

void	cleanup_arrays(t_mini *mini)
{
	if (mini -> token_list)
	{
		free_tokens(mini -> token_list);
		mini->token_list = NULL;
	}
	if (mini -> command_list)
	{
		free_commands(mini -> command_list);
		mini->command_list = NULL;
	}
}
