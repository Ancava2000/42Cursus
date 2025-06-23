/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:25:05 by acarro-v          #+#    #+#             */
/*   Updated: 2025/06/23 16:30:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initialize_mini(t_mini *mini)
{
	mini -> token_list = NULL;
	mini -> simple_command = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	t_mini	mini;

	if (ac != 1 || av[1])
		return (ft_error("Just the name of the executable"));
	initialize_mini(&mini);
	while (1)
	{
		lexer(&mini);
		parser(&mini);
	}
	return (0);
}
