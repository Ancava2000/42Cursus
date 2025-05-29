/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:28:00 by acarro-v          #+#    #+#             */
/*   Updated: 2025/05/27 13:20:17 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
