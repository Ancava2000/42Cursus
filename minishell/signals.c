/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:42:30 by kali              #+#    #+#             */
/*   Updated: 2025/06/24 15:03:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//falta ctrl d

#include "minishell.h"

void	ctrl_c_signal(int sig)
{
	printf("\n");
	if (g_signal == 0)
		g_signal = sig;
}

void	ctrl_c_in_main(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}