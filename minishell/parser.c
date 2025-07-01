/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:52:38 by kali              #+#    #+#             */
/*   Updated: 2025/07/01 13:23:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//EN PARSER (process token) HACE FALTA EL MINI PARA PASARSELO A LAS REDIRECCIONES, QUE A SU VEZ LO PASA EN EL HEREDOC.
//ESTO YA QUE SI HAY EXPANSION, ES NECESARIO SABER LA PALABRA QUE SE EXPANDE CON EL ENV GUARDADO EN UNA VARIABLE DE MINI. 

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
		cmd->command_name = add_word_to_array(tkn -> token_name, cmd -> command_name);
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
			tkn = proccess_token(mini, tkn, cmd);
		if (g_signal)
		{
			mini -> exit_status = 130; //código de salida de ctrl c
			free(cmd);
			g_signal = 0;
			break ;
		}
		new_command(mini, cmd);
		if (tkn && tkn -> token_type == 0)
			tkn = tkn -> next;
	}
}

/*
void	print_commands(t_mini *mini)
{
	t_command	*cmd;
	int			i;
	int			cmd_num = 1;

	cmd = mini->simple_command;
	while (cmd)
	{
		printf("🔹 Comando #%d:\n", cmd_num++);
		i = 0;
		if (cmd->command_name && cmd->command_name[0])
		{
			printf("   📘 command_name: ");
			while (cmd->command_name[i])
			{
				printf("%s ", cmd->command_name[i]);
				i++;
			}
			printf("\n");
		}
		else
			printf("   ⚠️  (sin nombre de comando)\n");

		if (cmd->infile >= 0)
			printf("   🔻 infile: %d\n", cmd->infile);
		else if (cmd->infile == -1)
			printf("   ⛔ infile: heredoc cancelado\n");

		if (cmd->outfile >= 0)
			printf("   🔺 outfile: %d\n", cmd->outfile);

		printf("\n");
		cmd = cmd->next;
	}
}
*/