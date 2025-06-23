/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:28:00 by acarro-v          #+#    #+#             */
/*   Updated: 2025/05/29 13:51:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax(char *line)
{
	while (*line)
	{
		if ((*line == '<' && (*(line + 1) == '>' || *(line + 1) == '|'))
			|| (*line == '>' && (*(line + 1) == '<' || *(line + 1) == '|'))
			|| (*line == '|' && (*(line + 1) == '<'
					|| *(line + 1) == '>' || *(line + 1) == '|')))
			return (1);
		line++;
	}
	return (0);
}


int	count_quotes(char *string)
{
	int	double_quote;
	int	single_quote;
	int	i;

	double_quote = 0;
	single_quote = 0;
	i = -1;
	while (string[++i])
	{
		if (string[i] == 34)
			double_quote += 1;
		if (string[i] == 39)
			single_quote += 1;
	}
	if ((double_quote > 0 && double_quote % 2 != 0)
		|| (single_quote > 0 && single_quote % 2 != 0))
		return (1);
	return (0);
}
