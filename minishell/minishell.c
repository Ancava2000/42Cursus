/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:25:05 by acarro-v          #+#    #+#             */
/*   Updated: 2025/06/30 07:09:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	initialize_mini(t_mini *mini, char **av)
{
	mini -> token_list = NULL;
	mini -> simple_command = NULL;
	mini -> exit_status = -1;
	mini -> program_name = av[0];
	return (0);
}

int	main(int ac, char **av)
{
	t_mini	mini;

	if (ac != 1 || av[1])
		return (ft_error("Just the name of the executable"));
	initialize_mini(&mini, av);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ctrl_c_in_main);
		lexer(&mini);
		parser(&mini);
		//print_commands(&mini);
	}
	return (0);
}
