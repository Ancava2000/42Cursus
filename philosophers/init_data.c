/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:43:13 by kali              #+#    #+#             */
/*   Updated: 2025/04/02 14:07:54 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_one_philo(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_threads(philo -> table);
    set_value_long(&philo -> lock_philo, &philo -> last_eaten, current_time(MILISECONDS));
    count_nb_threads(&philo ->table -> lock_simulation, &philo ->table -> nb_threads_run);
    messages(1, philo);
    while (!simulation_finish(philo->table))
        usleep(200);
    return(NULL);
}

void init_threads(t_table *table)
{
    int i;
    
    i = -1;
    if (table -> nb_philos == 1)
        pthread_create(&table->philos[0].thread_id, NULL, &ft_one_philo, &table->philos[0]);
    else
    {
        while (++i < table -> nb_philos)
        {
            if (pthread_create(&table -> philos[i].thread_id, NULL, &launcher,  &table -> philos[i]) != 0)
                ft_error("Error creating thread");
        }
    }
    pthread_create(&table -> check_end, NULL, &monitor, &table);
    table -> start_time = current_time(MILISECONDS);
    set_value_bool(&table -> lock_simulation, &table -> threads_ready, true);
    i = -1;
    while (++i < table -> nb_philos)
    {
        if (pthread_join(table->philos[i].thread_id, NULL) != 0)
                ft_error("Error joining threads");
    }
    //pthread_join(table->check_end, NULL);
    set_value_bool(&table->lock_simulation, &table->end_dinner, true);
}

void init_philo(t_table *table)
{
    int i;

    i = -1;
    while(++i < table -> nb_philos)
    {
        pthread_mutex_init(&table -> philos[i].lock_philo, NULL);
        table -> philos[i].philo_id = i + 1;
        table -> philos[i].full = false;
        table -> philos[i].meals_counter = 0;
        table -> philos[i].table = table;
        table -> philos[i].right_fork = &table -> forks[(i + 1) % table -> nb_philos];
        table -> philos[i].left_fork = &table -> forks[i];
        if (table -> philos[i].philo_id % 2 == 0)
        {
            table -> philos[i].right_fork = &table -> forks[i];
            table -> philos[i].left_fork = &table -> forks[(i + 1) % table -> nb_philos];
        }
    }
    init_threads(table);
}

void init_data(t_table *table)
{
    int i;

    i = -1;
    table -> threads_ready = false;
    table -> nb_threads_run = 0;
    table -> end_dinner = false;
    pthread_mutex_init(&table -> lock_write, NULL);
    pthread_mutex_init(&table -> lock_simulation, NULL);
    table -> philos = malloc(sizeof(t_philo) * table -> nb_philos);
    if (!table -> philos)
        ft_error("Error during malloc");
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
