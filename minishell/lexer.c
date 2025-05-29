/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:14 by acarro-v          #+#    #+#             */
/*   Updated: 2025/05/27 13:12:33 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(t_mini *mini)
{
	char	*line;

	line = readline("Minishell-> ");
	add_history(line);
	if (count_quotes(line))
		return (ft_error("Wrong number of quotes"));
	if (count_tokens(mini, line))
		return (ft_error("Error with tokens"));
	return (0);
}
