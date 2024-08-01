/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:05:50 by acarro-v          #+#    #+#             */
/*   Updated: 2024/07/17 10:18:26 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_banner(void)
{
	write(1, "  __  __ _       _ _        _ _    _  _ ___  \n", 47);
	write(1, " |  \\/  (_)     (_) |      | | |  | || |__ \\ \n", 47);
	write(1, " | \\  / |_ _ __  _| |_ __ _| | | _| || |_ ) | \n", 48);
	write(1, " | |\\/| | | '_ \\| | __/ _` | | |/ /__   _/ / \n", 47);
	write(1, " | |  | | | | | | | || (_| | |   <   | |/ /_ \n", 47);
	write(1, " |_|  |_|_|_| |_|_|\\__\\__,_|_|_|\\_\\  |_|____| \n", 48);
}

void	ft_putnbr(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	handle_signal(int signal)
{
	static int	bit;
	static int	current_char;
	int			nb;

	if (signal == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	current_char = (current_char << 1) + nb;
	bit++;
	if (bit == 8)
	{
		write(1, &current_char, 1);
		bit = 0;
		current_char = 0;
	}
}

int	main(void)
{
	ft_banner();
	write(1, "\n", 1);
	write(1, "Welcome to my server\n", 22);
	write(1, "The server is running, The PID number is: ", 43);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	write(1, "\n", 1);
	return (0);
}
