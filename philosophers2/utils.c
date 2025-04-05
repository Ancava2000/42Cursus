/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:36:07 by kali              #+#    #+#             */
/*   Updated: 2025/04/05 10:30:22 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	messages(int nb, t_philo *philo)
{
	long time;

	pthread_mutex_lock(philo->philo_mutex.lock_write);
	time = current_time() - philo->start_time;
	if (nb == 1 || nb == 2)
		printf(WHITE"%llu"RESET"%6d has taken a fork\n"RESET, time, philo-> philo_id);
	else if (nb == 3)
		printf(WHITE"%llu"RED"%6d is eating 🍝" "\t\t\t"YELLOW"[🍝 %ld 🍝]\n"RESET, time, philo-> philo_id, philo -> meals_counter);
	else if (nb == 4)
		printf(WHITE"%llu" BLUE"%6d is sleeping 💤\n"RESET, time, philo-> philo_id);
	else if (nb == 5)
		printf(WHITE"%llu"GREEN"%6d is thinking 🤔\n"RESET, time, philo-> philo_id);
	else if (nb == 6)
		printf("%6d died ☠️\n", philo-> philo_id);
	pthread_mutex_unlock(philo->philo_mutex.lock_write);
}

void	ft_error(const char *str, int nb)
{
	printf(RED"%s\n"RESET, str);
	exit(nb);
}

void	ft_clean(t_table *table, int count)
{
	while(--count >= 0)
		pthread_mutex_destroy(&table->forks[count]);
	pthread_mutex_destroy(&table->lock_meal);
	pthread_mutex_destroy(&table->lock_write);
}

long	current_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_error("Error with gettimeofday", 1);
	return((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

void	precise_usleep(long timestamp)
{
	long	start;
	long	time_passed;
	long	time_remaining;
	
	start = current_time();
	while(current_time() - start < timestamp)
	{
		time_passed = current_time() - start;
		time_remaining = timestamp - time_passed;
		if (time_remaining > 1e3)
			usleep(200);
		else
			while(current_time() - start < timestamp)
				;
	}
}