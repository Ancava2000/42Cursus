/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:42:28 by kali              #+#    #+#             */
/*   Updated: 2025/04/06 17:17:14 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_death(t_table *table)
{
    int i;
    long now;

    i = 0;
    while (i < table->nb_philos)
    {
        pthread_mutex_lock(&table->lock_meal);
        now = get_current_time();
        if ((now - table->philos[i].last_eaten) >= table->time_to_die)
        {
            messages(6, &table->philos[i]); 
            pthread_mutex_lock(&table->lock_simulation);
            table->end_dinner = true;
            pthread_mutex_unlock(&table->lock_simulation);
            pthread_mutex_unlock(&table->lock_meal);
            return; 
        }
        pthread_mutex_unlock(&table->lock_meal);
        i++;
    }
}

void check_all_ate(t_table *table)
{
    int i;
    int full = 0;

    if (table->nb_meals > 0) 
    {
        i = 0;
        while (i < table->nb_philos)
        {
            pthread_mutex_lock(&table->lock_meal);
            if (table->philos[i].meals_eaten == table->nb_meals)
                full++;
            pthread_mutex_unlock(&table->lock_meal);
            i++;
        }
        if (full == table->nb_philos)
        {
            pthread_mutex_lock(&table->lock_simulation);
            table->end_dinner = true;
            pthread_mutex_unlock(&table->lock_simulation);
        }
    }
}

void *monitor(void *data)
{
    t_table *table = (t_table *)data;

    while (!table->end_dinner)
    {
        check_death(table);
        check_all_ate(table);
    }
    return (NULL);
}
