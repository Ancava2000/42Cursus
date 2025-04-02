/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:31 by kali              #+#    #+#             */
/*   Updated: 2025/04/02 14:31:28 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool check_died(t_philo *philo)
{
  long  time_passed;
  long  t_to_die;
  
  if (lock_get_bool(&philo -> lock_philo, &philo->full))
    return (false);
  t_to_die = philo->table->time_to_die;  
  time_passed = current_time(MILISECONDS) - lock_get_long(&philo -> lock_philo, &philo -> last_eaten);
  if (time_passed > t_to_die)
      return (true);
  return (false);
}

void *monitor(void *data)
{
    t_table *table;
    int i;

    table = (t_table *)data;
    while (!all_threads_run(&table->lock_simulation, &table->nb_threads_run, table->nb_philos))
        usleep(100);
    while (!simulation_finish(table))
    {
        i = -1;
        while (++i < table->nb_philos && !simulation_finish(table))
        {
            if (check_died(table->philos + i))
            {
                set_value_bool(&table->lock_simulation, &table->end_dinner, true);
                messages(6, table->philos + i);
                break;
            }
        }
        usleep(100);
    }
    return (NULL);
}

void    think(t_philo *philo)
{
    messages(5, philo);
}

void  eat(t_philo *philo)
{
  pthread_mutex_lock(&philo ->left_fork -> fork);
  messages(1, philo);
  pthread_mutex_lock(&philo ->right_fork -> fork);
  messages(2, philo);
  set_value_long(&philo -> lock_philo, &philo -> last_eaten, current_time(MILISECONDS));
  philo -> meals_counter++;
  messages(3, philo);
  precise_usleep(philo->table->time_to_eat, philo->table);
  if (philo ->table ->nb_meals > 0 && (philo -> meals_counter == philo->table->nb_meals))
      set_value_bool(&philo -> lock_philo, &philo -> full, true);
  pthread_mutex_unlock(&philo ->left_fork->fork);
  pthread_mutex_unlock(&philo ->right_fork->fork);
}

void  *launcher(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;

    wait_threads(philo -> table);
    set_value_long(&philo -> lock_philo, &philo -> last_eaten, current_time(MILISECONDS));
    count_nb_threads(&philo ->table -> lock_simulation, &philo ->table -> nb_threads_run);
    while(!simulation_finish(philo->table))
    {
        if (philo->full)
            //break ;
            exit(EXIT_SUCCESS);
        eat(philo);
        messages(4, philo);
        precise_usleep(philo ->table-> time_to_sleep, philo->table);
        think(philo);
    }
}
