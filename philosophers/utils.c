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

void	messages(int i, t_philo *philo)
{
	if (i == 1)
		printf(BLUE"%d has taken the left fork\n"RESET, philo -> philo_id);
	else if (i == 2)
		printf(BLUE "%d has taken the right fork\n"RESET, philo -> philo_id);
	else if (i == 3)
		printf(%d "is eaten", philo -> philo_id);
	else if (i == 4)
		printf(%d "is sleeping", philo -> philo_id);
	else if (i == 5)
		printf(%d "is thinking", philo -> philo_id);
	else if (i == 6)
		printf(%d "died", philo -> philo_id);
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

long long	current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
