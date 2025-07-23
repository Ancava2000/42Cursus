/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:09 by acarro-v          #+#    #+#             */
/*   Updated: 2025/07/21 13:44:32 by kali             ###   ########.fr       */
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

//EL HEREDOC (<<) SEGUIDO DE PALABRAS CON COMILLAS NO EXPANDE
//SI NO TIENE COMILLAS SI EXPANDE LAS VARIABLES
//comprobar < seguido de < y si luego hay ' o "
//se puede hacer una funcion por un lado que guarde el valor del token
//y en otra que segun el valor, se insert node y se return 2 o 1.
//vaya dicidir esta funcion en dos.

void	token_type(t_mini *mini, char **line)
{
	int	index;

	if (**line == '<' && *(*line + 1) == '<' && ++*line && ++*line)
	{
		index = 0;
		while ((*line)[index] == 32
		|| ((*line)[index] > 8 && (*line)[index] < 14))
			index++;
		if ((*line)[index] == '\'' || (*line)[index] == '\"')
			insert_node(mini, "<<", 1);
		else
			insert_node(mini, "<$", 1);
	}
	else if (**line == '>' && *(*line + 1) == '>' && ++*line && ++*line)
		insert_node(mini, ">>", 1);
	else if (**line == '<' && ++*line)
		insert_node(mini, "<", 1);
	else if (**line == '>' && ++*line)
		insert_node(mini, ">", 1);
	else if (**line == '|' && ++*line)
		insert_node(mini, "|", 0);
}

void	check_word(t_mini *mini, char **line)
{
	int		j;
	char	*word;

	j = 0;
	word = ft_calloc(sizeof(char), 4096);
	while (**line && **line != ' ' && **line != '<'
		&& **line != '>' && **line != '|')
	{
		if (**line == '\"' && ++*line)
			j += handle_double_quotes(mini, line, &word);
		else if (**line == '\'' && ++*line)
			j += handle_single_quotes(line, &word);
		else if (**line == '$' && (*(*line + 1) == '?'
				|| ft_isalnum(*(*line + 1))) && ++*line)
			j += expand_word(mini, line, &word);
		else
			word[j++] = *(*line)++;
	}
	if (j > 0)
		insert_node(mini, word, 2);
	free(word);
}

int	count_tokens(t_mini *mini, char *line)
{
	while (*line)
	{
		while (*line == 32
			|| (*line > 8 && *line < 14))
			line++;
		if (*line == '<' || *line == '>'
			|| *line == '|')
			token_type(mini, &line);
		else
			check_word(mini, &line);
	}
	print_tokens(mini);
	if (check_syntax(line))
		return (1);
	return (0);
}

/*
void	print_tokens(t_mini *mini)
{
	t_token	*token;

	token = mini->token_list;
	while (token)
	{
		printf("TOKEN: '%s' | TYPE: %d\n", token->token_name, token->token_type);
		token = token->next;
	}
}
*/