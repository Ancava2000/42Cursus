/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:13:28 by kali              #+#    #+#             */
/*   Updated: 2025/04/06 17:26:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    think(t_philo *philo)
{
    messages(5, philo);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(philo->first_fork);
    messages(1, philo);
    pthread_mutex_lock(philo->second_fork);
    messages(2, philo);
    pthread_mutex_lock(&philo->table->lock_meal);
    philo->last_eaten = get_current_time();
    philo->meals_eaten++;
    messages(3, philo);
    precise_usleep(philo->table->time_to_eat, philo->table);
    pthread_mutex_unlock(&philo->table->lock_meal);
    pthread_mutex_unlock(philo->first_fork);
    pthread_mutex_unlock(philo->second_fork);
}

void    *dinner(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;

    philo->last_eaten = get_current_time();
    while(!philo->table->end_dinner)
    {
        eat(philo);
        messages(4, philo);
        if (philo->table->end_dinner)
            break ;
        precise_usleep(philo->table->time_to_sleep, philo->table);
        think(philo);
        if (philo->table->end_dinner)
            break ;
    }
    return (NULL);
}