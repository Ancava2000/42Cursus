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

void	messages(int i, t_philo *philo, char *str)
{
	long long time;

	pthread_mutex_lock(&philo->table->lock_write);
	time = current_time() - philo -> table -> start_time;
	if (i == 6 && philo -> table -> dead == 0)
	{
		printf("%llu %d %s\n", time, philo-> philo_id, str);
		philo -> table -> dead = 1;
	}
	if (!philo -> table -> dead)
		printf("%llu %d %s\n", time, philo-> philo_id, str);
	pthread_mutex_unlock(&philo->table->lock_write);
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
