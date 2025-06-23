/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:52:38 by kali              #+#    #+#             */
/*   Updated: 2025/06/23 16:31:04 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	cmd -> next = NULL;	
	return (cmd);
}

t_token	*proccess_token(t_token *tkn, t_command *cmd)
{
	if (tkn -> token_type == 1)
	{
		redirections(tkn -> token_name, tkn->next->token_name, cmd);
		tkn = tkn -> next;
	}
	else if (tkn -> token_type == 2)
		cmd->command_name = add_word(tkn -> token_name, cmd -> command_name);
	tkn = tkn -> next;
	return (tkn);
}

void	new_command(t_mini *mini, t_command *cmd)
{
	t_command *last;

	if (!mini->simple_command)
		mini -> simple_command = cmd;
	else
	{
		last = mini->simple_command;
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
			tkn = proccess_token(tkn, cmd);
		new_command(mini, cmd);
		if (tkn && tkn -> token_type == 0)
			tkn = tkn -> next;
	}
}
