/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:11:19 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/17 13:25:46 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ctrl_quit(int sig)
{
	(void)sig;
	if (rl_line_buffer && *rl_line_buffer)
	{
		printf("\n");
		printf("Quit (core dumped)\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		exit(131);
	}
}

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
