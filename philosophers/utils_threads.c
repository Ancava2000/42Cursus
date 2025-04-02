/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:45:39 by kali              #+#    #+#             */
/*   Updated: 2025/04/02 13:58:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    wait_threads(t_table *table)
{
    while (!(lock_get_bool(&table -> lock_simulation, &table -> threads_ready)))
    ;
}

bool     all_threads_run(t_mtx *mutex, long *threads, long philo_nb)
{
    bool res;

    res = false;
    pthread_mutex_lock(mutex);
    if (*threads == philo_nb)
        res = true;
    pthread_mutex_unlock(mutex);
    return (res);
}

void    count_nb_threads(t_mtx *mutex, long *value)
{
    pthread_mutex_lock(mutex);
    (*value)++;
    pthread_mutex_unlock(mutex);
}