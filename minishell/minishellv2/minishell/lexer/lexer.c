/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:11:42 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/17 13:27:29 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_syntax_double(char *line)
{
	int	in_single_quotes;
	int	in_double_quotes;

	in_single_quotes = 0;
	in_double_quotes = 0;
	while (*line)
	{
		if (*line == '\'' && !in_double_quotes)
			in_single_quotes = 1;
		else if (*line == '\"' && !in_single_quotes)
			in_double_quotes = 1;
		else if (!in_single_quotes && !in_double_quotes)
		{
			if ((*line == '<' && (*(line + 1) == '>' || *(line + 1) == '|'))
				|| (*line == '>' && (*(line + 1) == '<' || *(line + 1) == '|'))
				|| (*line == '|' && (*(line + 1) == '<'
						|| *(line + 1) == '>' || *(line + 1) == '|')))
				return (2);
		}
		line++;
	}
	return (0);
}

int	count_quotes(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '"')
		{
			i++;
			while (string[i] && string[i] != '"')
				i++;
			if (!string[i])
				return (1);
		}
		else if (string[i] == '\'')
		{
			i++;
			while (string[i] && string[i] != '\'')
				i++;
			if (!string[i])
				return (1);
		}
		if (string[i])
			i++;
	}
	return (0);
}

int	handle_double_quotes(t_mini *mini, char **line, char **word, int start_pos)
{
	int	j;

	j = 0;
	while (**line && **line != '\"')
	{
		if (**line == '$' && (*(*line + 1) == '?'
				|| ft_isalnum(*(*line + 1))) && ++(*line))
			j += expand_word(mini, line, word);
		else
			(*word)[start_pos + j++] = *(*line)++;
	}
	if (**line == '\"')
		(*line)++;
	else
		return (1);
	return (j);
}

int	handle_single_quotes(char **line, char **word, int start_pos)
{
	int	j;

	j = 0;
	while (**line && **line != '\'')
		(*word)[start_pos + j++] = *(*line)++;
	if (**line == '\'')
		(*line)++;
	else
		return (1);
	return (j);
}

int	lexer(t_mini *mini, char *line)
{
	if (count_quotes(line))
		return (ft_error("Wrong number of quotes"));
	if (count_tokens(mini, line))
		return (ft_error("Error with tokens"));
	return (0);
}
