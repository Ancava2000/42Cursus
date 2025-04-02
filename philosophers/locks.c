/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:14 by kali              #+#    #+#             */
/*   Updated: 2025/04/02 14:23:35 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_value_long(t_mtx *mutex, long *dest, long value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}

void set_value_bool(t_mtx *mutex, bool *dest, bool value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}

bool  lock_get_bool(t_mtx *mutex, bool *value)
{
    bool    res;

    pthread_mutex_lock(mutex);
    res = *value;
    pthread_mutex_unlock(mutex);
    return (res);
}

long  lock_get_long(t_mtx *mutex, long *value)
{
    long    res;

    pthread_mutex_lock(mutex);
    res = *value;
    pthread_mutex_unlock(mutex);
    return (res);
}

bool    simulation_finish(t_table *table)
{
    return(lock_get_bool(&table->lock_simulation, &table->end_dinner));
}