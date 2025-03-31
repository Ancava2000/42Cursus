/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:43:13 by kali              #+#    #+#             */
/*   Updated: 2025/03/27 11:35:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_threads(t_table *table)
{
    int i;
    
    i = -1;
    if (table -> nb_philos == 1)
    ft_one_case(&table);
    else
    {
        while (++i < table -> nb_philos)
        {
            if (phtread_create(&table -> philos[i].thread_id, NULL, &philo_routine,  &table -> philos[i]) != 0)
                ft_error("Error creating thread");
        }
        i = -1
        while (++i < table -> nb_philos)
        {
            if (phtread_join(table -> philos[i].thread_id, NULL) != 0)
                ft_error("Error joining threads");
        }
    }
}

void init_philo(t_table *table)
{
    int i;

    table -> start_time = current_time();
    i = -1;
    while(++i < table -> nb_philos)
    {
        table -> philos[i].philo_id = i + 1;
        table -> philos[i].has_eaten = 0;
        table -> philos[i].nb_meals = 0;
        table -> philos[i].table = table; 
        if (table -> philos[i].philo_id % 2 == 0)
        {
            table -> philos[i].right_fork = &table -> forks[i];
            table -> philos[i].left_fork = &table -> forks[(i + 1) % table -> nb_philos];
        }
        else
        {
            table -> philos[i].right_fork = &table -> forks[(i + 1) % table -> nb_philos];
            table -> philos[i].left_fork = &table -> forks[i];
        }
    }
    init_threads(&table);
}

void init_data(t_table *table)
{
    int i;

    i = -1;
    table -> start_time = 0;
    table -> dead = 0;
    pthread_mutex_init(&table -> lock_write, NULL);
    pthread_mutex_init(&table -> lock_check, NULL);
    pthread_mutex_init(&table -> lock_dead, NULL);
    pthread_mutex_init(&table -> lock_eat, NULL);
    table -> philos = malloc(sizeof(t_philo) * table -> nb_philos);
    if (!table -> philos)
    {
        free(table -> philos);
        ft_error("Error during malloc");
    }
    table -> forks = malloc(sizeof(t_fork) * table -> nb_philos);
    if (!table -> forks)
        ft_error("Error during malloc");
    while (++i < table -> nb_philos)
    {
        pthread_mutex_init(&table -> forks[i].fork ,NULL);
        table -> forks[i].fork_id = i;
    }
    init_philo(table);
}
