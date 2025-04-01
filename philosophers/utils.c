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

void	messages(int nb, t_philo *philo)
{
	long time;

	pthread_mutex_lock(&philo -> table -> lock_write);
	time = current_time() - philo -> table -> start_time;
	if (nb == 1 && !(philo -> table -> end_dinner))
		printf("%llu %d has taken the left fork\n", time, philo-> philo_id);
	else if (nb == 2 && !(philo -> table -> end_dinner))
		printf("%llu %d has taken the right fork\n", time, philo-> philo_id);
	else if (nb == 3 && !(philo -> table -> end_dinner))
		printf("%llu %d is eating\n", time, philo-> philo_id);
	else if (nb == 4 && !(philo -> table -> end_dinner))
		printf("%llu %d is sleeping\n", time, philo-> philo_id);
	else if (nb == 5 && !(philo -> table -> end_dinner))
		printf("%llu %d is thinking\n", time, philo-> philo_id);
	else if (nb == 6)
		printf("%llu %d died\n", time, philo-> philo_id);
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

	if (gettimeofday(&tv, NULL) == -1);
		ft_error("Error getting timestamp");
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	precise_usleep(long long time)
{
	long long start;

	start = current_tinme();
	while (current_time() - start < time)
		usleep(500);
}
