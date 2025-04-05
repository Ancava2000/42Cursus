/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:44:39 by kali              #+#    #+#             */
/*   Updated: 2025/04/05 11:23:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// id = 1 + i, for messages, clearer
// philos position start from 0 and forks from 0

void    init_philos(t_table *table, t_philo *philo, t_mutex *forks, char **av)
{
    int     i;

    i = -1;
    while(++i < philo->nb_philos)
    {
        philo[i].philo_id = i + 1;
        philo[i].nb_philos = ft_atoi2(av[1]);
        philo[i].time_to_die = ft_atoi2(av[2]);
        philo[i].time_to_eat = ft_atoi2(av[3]);
        philo[i].time_to_sleep = ft_atoi2(av[4]);
        //philo[i].last_eat = current_time();
        //philo[i].start_time = current_time();
        philo[i].meals_counter = 0;
        philo[i].nb_meals = -1;
        if (av[5])
            philo[i].nb_meals= ft_atoi2(av[5]);
        philo[i].philo_mutex.left_fork = &forks[i];
        philo[i].philo_mutex.right_fork = &forks[(i + 1) % philo->nb_philos];
        philo[i].philo_mutex.lock_write = &table->lock_write;
        philo[i].philo_mutex.lock_meal = &table->lock_meal;
    }
}

void    init_forks(t_table *table, t_mutex *forks, int nb_forks)
{
    int     i;
    
    i = -1;
    while(++i < nb_forks)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
            exit(EXIT_FAILURE);
    }
}

void    init_table(t_table *table, t_philo *philo, t_mutex *forks, char **av)
{
    table->forks = forks;
    table->philos = philo;
    if (pthread_mutex_init(&table->lock_meal, NULL) != 0
    || pthread_mutex_init(&table->lock_write, NULL) != 0)
        exit(EXIT_FAILURE);
}