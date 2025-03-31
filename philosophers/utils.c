/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:16:51 by acarro-v          #+#    #+#             */
/*   Updated: 2025/03/27 11:30:35 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_table *table)
{
	int i;

	i = -1;
	while (++i < table -> nb_philos)
	{
		pthread_mutex_destroy(&table -> philos[i].left_fork);
		pthread_mutex_destroy(&table -> philos[i].right_fork);
	}
	free(table -> philos);
	free(table -> forks);
}
void	ft_error(const char *str)
{
	printf(RED"%s\n"RESET, str);
	exit(EXIT_FAILURE);
}

void ft_error_2(void)
{
	printf(RED"The arguments are:\n"RESET);
	printf(BLUE"1. Number of philo\n"RESET);
	printf(BLUE"2. Time To Die (in milliseconds)\n"RESET);
	printf(BLUE"3. Time To Eat (in milliseconds)\n"RESET);
	printf(BLUE"3. Time To Eat (in milliseconds)\n"RESET);
	printf(BLUE"(optional) 5. Nb of meals\n"RESET);
}
/*
void message(int i)
{
	if (i == 1)
	{
		printf()
		exit(EXIT_SUCCESS);
	}
	else if (1 == 2)
	else if (1 == 3)
	else if (1 == 4)
	else if (1 == 5)
	else if (1 == 6)
}
*/
