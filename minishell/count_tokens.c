/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:09 by acarro-v          #+#    #+#             */
/*   Updated: 2025/05/29 14:38:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_node(t_mini *mini, char *line, int t_type)
{
	t_token	*new;
	t_token	*temp;

	new = malloc(sizeof(t_token));
	if (!new)
	{
		free(new);
		exit (1);
	}
	new -> token_name = ft_strdup(line);
	new -> token_type = t_type;
	new -> next = NULL;
	if (!mini -> token_list)
		mini -> token_list = new;
	else
	{
		temp = mini -> token_list;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
}

int	token_type(int i, t_mini *mini, char *line)
{
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
		{
			insert_node(mini, "<<", 1);
			return (2);
		}
		insert_node(mini, "<", 1);
		return (1);
	}
	else if (line[i] == '>')
	{
		if (line[i + 1] == '>')
		{
			insert_node(mini, ">>", 1);
			return (2);
		}
		insert_node(mini, ">", 1);
		return (1);
	}
	else if (line[i] == '|')
	{
		insert_node(mini, "|", 0);
		return (1);
	}
	return (0);
}

int	check_word(int i, t_mini *mini, char *line)
{
	int		start;
	int		j;
	char	word[1024];

	start = i;
	while (line[i] == ' ' || line[i] == '<'
		|| line[i] == '>' || line[i] == '|')
		i++;
	if (!line[i])
		return (1);
	j = 0;
	while (line[i] && line[i] != ' ')
	{
		if (line[i] != '\"' && line[i] != '\'')
			word[j++] = line[i];
		i++;
	}
	word[j] = '\0';
	insert_node(mini, word, 2);
	return (i - start);
}

// SE PUEDE QUITAR LO DE I y J. LA CUENTA DE LOS TOKEN
// SE HACE EN LA FUNCION DEL TOKEN PARA SALTAR TODO
int	count_tokens(t_mini *mini, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i] == 32
			|| (line[i] > 8 && line[i] < 14))
			i++;
		if (line[i] == '<' || line[i] == '>'
			|| line[i] == '|')
			j += token_type(i, mini, line);
		else
			j += check_word(i, mini, line);
		i = j + i;
	}
	if (check_syntax(line))
		return (1);
	print_tokens(mini);
	return (0);
}

void	print_tokens(t_mini *mini)
{
	t_token	*current = mini->token_list;

	while (current)
	{
		printf("TOKEN: %-10s | TYPE: %d\n", current->token_name, current->token_type);
		current = current->next;
	}
}
