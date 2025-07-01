/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:14 by acarro-v          #+#    #+#             */
/*   Updated: 2025/06/23 15:46:34 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(t_mini *mini)
{
	char	*line;

	line = readline("Minishell-> ");
	add_history(line);
	if (count_quotes(line))
		ft_error("Wrong number of quotes");
	if (count_tokens(mini, line))
		ft_error("Error with tokens");
}
