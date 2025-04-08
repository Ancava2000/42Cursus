/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:54:43 by kali              #+#    #+#             */
/*   Updated: 2025/04/08 16:08:02 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_error(const char *str, int nb)
{
    printf(RED"%s\n"RESET, str);
    return(nb);
}

void	messages(int nb, t_philo *philo)
{
	long time;

	pthread_mutex_lock(&philo->table->lock_write);
    time = get_current_time() - philo->table->start_dinner;
	if (nb == 1 || nb == 2)
		printf(WHITE"%ld"RESET"%6d has taken a fork\n"RESET, time, philo-> philo_id);
	else if (nb == 3)
		printf(WHITE"%ld"RED"%6d is eating 🍝" "\t\t\t"YELLOW"[🍝 %d 🍝]\n"RESET, time, philo-> philo_id, philo -> meals_eaten);
	else if (nb == 4)
		printf(WHITE"%ld" BLUE"%6d is sleeping 💤\n"RESET, time, philo-> philo_id);
	else if (nb == 5)
		printf(WHITE"%ld"GREEN"%6d is thinking 🤔\n"RESET, time, philo-> philo_id);
	else if (nb == 6)
		printf(RED"%6d died ☠️\n"RESET, philo-> philo_id);
	pthread_mutex_unlock(&philo->table->lock_write);
}

long    get_current_time(void)
{
    struct timeval  tv;

    if (gettimeofday(&tv, NULL))
        ft_error("Error with gettimeofday", 1);
    return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));

}

void    precise_usleep(long timestamp, t_table *table)
{
    long    start;

    start = get_current_time();
    while(get_current_time() - start < timestamp)
    {
        if (table->end_dinner)
            break ;
        usleep(1000);
    }
}

void    ft_clean(t_table *table)
{
    int i;

    i = -1;
    while(++i < table->nb_philos)
        pthread_mutex_destroy(&table->forks[i]);
    pthread_mutex_destroy(&table->lock_write);
    pthread_mutex_destroy(&table->lock_meal);
    pthread_mutex_destroy(&table->lock_simulation);
    free(table->forks);
    free(table->philos);
}