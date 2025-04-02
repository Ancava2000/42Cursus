/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:16:51 by acarro-v          #+#    #+#             */
/*   Updated: 2025/04/02 13:15:12 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	messages(int nb, t_philo *philo)
{
	long time;

	time = current_time(MILISECONDS) - philo->table->start_time;
	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->table -> lock_write);
	if (nb == 1 || nb == 2 && !simulation_finish(philo->table))
		printf(WHITE"%llu"RESET"%6d has taken a fork\n"RESET, time, philo-> philo_id);
	else if (nb == 3 && !simulation_finish(philo->table))
		printf(WHITE"%llu"RED"%6d is eating 🍝" "\t\t\t"YELLOW"[🍝 %ld 🍝]\n"RESET, time, philo-> philo_id, philo -> meals_counter);
	else if (nb == 4 && !simulation_finish(philo->table))
		printf(WHITE"%llu" BLUE"%6d is sleeping 💤\n"RESET, time, philo-> philo_id);
	else if (nb == 5 && !simulation_finish(philo->table))
		printf(WHITE"%llu"GREEN"%6d is thinking 🤔\n"RESET, time, philo-> philo_id);
	else if (nb == 6)
		printf("%llu %6d died ☠️\n", time, philo-> philo_id);
	else if (nb == 7)
		printf(WHITE"%llu %5d is full \n"RESET, time, philo-> philo_id);
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

long	current_time(t_time_code code)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		ft_error("Error with timestamps");
	else if (code == MILISECONDS)
		return((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (code == MICROSECONDS)
		return((tv.tv_sec * 1e6) + (tv.tv_usec / 1e6));
}

void precise_usleep(long timestamp, t_table *table)
{
    long	start;
    long	time_passed;
	long	time_remaining;

	start = current_time(MICROSECONDS);
	while((current_time(MICROSECONDS)) - start < timestamp)
	{
		if (simulation_finish(table))
			break ;
		time_passed = current_time(MICROSECONDS) - start;
		time_remaining = timestamp - time_passed;
		if (time_remaining > 1e3)
			usleep(time_remaining / 2);
		else
		{
			while((current_time(MICROSECONDS)) - start < timestamp)
				;
		}
	}
}
