/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:06:20 by kali              #+#    #+#             */
/*   Updated: 2025/04/06 17:23:25 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_threads(t_table *table)
{
    int i;
    pthread_t monitor_thread;

    i = -1;
    if (table->nb_meals == 0)
        ft_error("At least indicate 1 meal", 1);
    table->start_dinner = get_current_time();
    while(++i < table->nb_philos)
        pthread_create(&table->philos[i].philo_thread, NULL, &dinner, &table->philos[i]);
    pthread_create(&monitor_thread, NULL, &monitor, table);
    pthread_join(monitor_thread, NULL);
    i = -1;
    while(++i < table->nb_philos)
        pthread_join(table->philos[i].philo_thread, NULL);
}

void    init_philos(t_table *table)
{
    t_philo *philo;
    int i;
    
    i = -1;
    while(++i < table->nb_philos)
    {
        philo = table->philos + i;
        philo->philo_id = i + 1;
        philo->meals_eaten = 0;
        philo->table = table;
        philo->first_fork = &table->forks[i];
        philo->second_fork = &table->forks[(i + 1) % table->nb_philos];
        if (philo->philo_id % 2 == 0)
        {
            philo->first_fork = &table->forks[(i + 1) % table->nb_philos];
            philo->second_fork = &table->forks[i];
        }
    }
   init_threads(table);
}

void    init_table(t_table *table)
{
    int i;
    table->end_dinner = false;
    pthread_mutex_init(&table->lock_write, NULL);
    pthread_mutex_init(&table->lock_meal, NULL);
    pthread_mutex_init(&table->lock_simulation, NULL);
    if (!(table->philos = malloc(sizeof(t_philo) * table->nb_philos)))
    {
        free(table->philos);
        ft_error("Error with malloc", 1);
    }
    if (!(table->forks = malloc(sizeof(t_mutex) * table->nb_philos)))
    {
        free(table->forks);
        ft_error("Error with malloc", 1);
    }
    i = -1;
    while(++i < table->nb_philos)
        pthread_mutex_init(&table->forks[i], NULL);
    init_philos(table);
}