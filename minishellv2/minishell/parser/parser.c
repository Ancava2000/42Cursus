/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:10:58 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/17 13:25:10 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*initialize_cmd(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		ft_error("Error allocating memory");
	cmd -> command_name = ft_calloc(sizeof(char *), 1);
	if (!cmd -> command_name)
		ft_error("Error allocating memory");
	cmd -> infile = -2;
	cmd -> outfile = -2;
	cmd -> pid = -1;
	cmd -> exit_code = -1;
	cmd -> next = NULL;
	return (cmd);
}

t_token	*proccess_token(t_mini *mini, t_token *tkn, t_command *cmd)
{
	if (tkn -> token_type == 1)
	{
		redirections(mini, tkn -> token_name, tkn->next->token_name, cmd);
		tkn = tkn -> next;
	}
	else if (tkn -> token_type == 2)
		cmd->command_name = add_word_to_array(tkn -> token_name,
				cmd -> command_name);
	tkn = tkn -> next;
	return (tkn);
}

void	new_command(t_mini *mini, t_command *cmd)
{
	t_command	*last;

	if (!mini->command_list)
		mini -> command_list = cmd;
	else
	{
		last = mini->command_list;
		while (last->next)
			last = last->next;
		last -> next = cmd;
	}
}

void	parser(t_mini *mini)
{
	t_command	*cmd;
	t_token		*tkn;

	tkn = mini -> token_list;
	while (tkn)
	{
		cmd = initialize_cmd();
		while (tkn && tkn -> token_type != 0)
			tkn = proccess_token(mini, tkn, cmd);
		if (g_signal)
		{
			mini -> exit_status = 128 + g_signal;
			free(cmd);
			g_signal = 0;
			break ;
		}
		new_command(mini, cmd);
		if (tkn && tkn -> token_type == 0)
			tkn = tkn -> next;
	}
}
