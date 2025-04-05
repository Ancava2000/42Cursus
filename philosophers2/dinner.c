/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:29:07 by kali              #+#    #+#             */
/*   Updated: 2025/04/05 11:25:55 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool is_all_eat(t_philo *philos)
{
    int finished;
    int i;

    i = -1;
    finished = 0;
    if (philos[0].nb_meals == -1)  // Si el número de comidas no está especificado, devolvemos false
        return (false);
    
    // Recorremos todos los filósofos
    while (++i < philos[0].nb_philos)
    {
        pthread_mutex_lock(philos[i].philo_mutex.lock_meal); // Usamos el mutex correspondiente al filósofo
        if (philos[i].meals_counter >= philos[i].nb_meals)  // Si el filósofo ha comido el número necesario de veces
            ++finished;
        pthread_mutex_unlock(philos[i].philo_mutex.lock_meal);
    }

    // Si todos los filósofos han comido el número necesario de veces
    if (finished == philos[0].nb_philos)
    {
        pthread_mutex_lock(philos[0].philo_mutex.lock_write); // Usamos el mutex global de escritura para las acciones
        return (true);
    }
    return (false);
}

// Función del hilo del observador que monitoriza el estado de los filósofos
void *monitor(void *ptr)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)ptr;
    while (true)
    {
        i = -1;
        // Recorremos todos los filósofos para ver si alguno ha muerto
        while (++i < philo[0].nb_philos)
        {
            pthread_mutex_lock(philo[i].philo_mutex.lock_meal); // Bloqueamos el mutex de la comida
            if (current_time() - philo[i].last_eat > philo[i].time_to_die) // Si el filósofo no ha comido en el tiempo permitido
            {
                pthread_mutex_lock(philo[i].philo_mutex.lock_write);  // Liberamos el mutex
                messages(6, philo);  // Imprimimos el mensaje de muerte
                pthread_mutex_unlock(philo[0].philo_mutex.lock_write);  // Bloqueamos el mutex global de escritura
                return (NULL);  // Terminamos el observador
            }
            pthread_mutex_unlock(philo[i].philo_mutex.lock_meal);  // Liberamos el mutex
        }
        // Verificamos si todos los filósofos han comido lo suficiente
        if (is_all_eat(philo))
            return (NULL);  // Terminamos el observador si todos han comido lo necesario
    }
    return (NULL);
}

void    philo_routine(t_philo *philo)
{
    pthread_mutex_lock(philo->philo_mutex.left_fork);
    messages(1, philo);
    pthread_mutex_lock(philo->philo_mutex.right_fork);
    messages(2, philo);
    pthread_mutex_lock(philo->philo_mutex.lock_meal);
    messages(3, philo);
    philo->meals_counter += 1;
    philo->last_eat = current_time();
    pthread_mutex_unlock(philo->philo_mutex.lock_meal);
    precise_usleep(philo->time_to_eat);
    pthread_mutex_unlock(philo->philo_mutex.left_fork);
    pthread_mutex_unlock(philo->philo_mutex.right_fork);
    messages(4, philo);
    precise_usleep(philo->time_to_sleep);
    messages(5, philo);
}

void    *start_dinner(void *data)
{
    t_philo *philo;

    printf("hola\n");
    philo = (t_philo *)data;
    if (philo->philo_id % 2 == 0)
        precise_usleep(philo->time_to_eat / 2);
    pthread_mutex_lock(philo->philo_mutex.lock_meal);
    philo->last_eat = current_time();
    philo->start_time = current_time();
    pthread_mutex_unlock(philo->philo_mutex.lock_meal);
    while(true)
        philo_routine(philo);
    return (NULL);
}


void    dinner(t_table *table, int count)
{
    int         i;
    pthread_t   monitor_id;

    i = -1;
    pthread_create(&monitor_id, NULL, &monitor, table->philos);
    while(++i < count)
    {
        if(pthread_create(&table->philos[i].philo_thread, NULL,
                        start_dinner, &table->philos[i]) != 0)
        {
                ft_clean(table, count);
                ft_error("Error creating threads", 1);
        }
    }
    pthread_join(monitor_id, NULL); // we do join with the monitor threads. With this, the iteration never end until the conditions are meet.
    i = -1;
    while(++i < count)
    {
        if (pthread_detach(table->philos[i].philo_thread) != 0) //we detach the philo threads to free resources. We use detach instead of join,
                                                            //  because the monitor is already iterating continously the threads.
        {
            ft_clean(table, count);
            ft_error("Error detaching threads", 1);
        }
    }
}