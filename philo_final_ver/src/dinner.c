#include "../include/philo.h"

/*
	1- Use the meal lock everytime we change meal variables.
	2. Get the current time for last_eaten.
	3. Sleep the time to eat indicated.
	4. Increase meals_eaten.
	5. Once increase, print the eat message with the number of meals eaten.
	6. Unlock.
*/
void	eat(t_philo *philo)
{
	messages(2, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
	pthread_mutex_lock(&philo->table->lock_meal);
	philo->last_eaten = get_now_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->lock_meal);
	precise_usleep(philo->table, philo->table->time_to_eat);
}

// Sleep message, sleep the indicated time.
void	diazepam(t_philo *philo)
{
	messages(3, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
	precise_usleep(philo->table, philo->table->time_to_sleep);
}

// Think message.
void	think(t_philo *philo)
{
	messages(4, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
}

/*
	Infinite loop with while(1):
		1. Check if one of the philos is full.
		2. If one is full, that philo exits the routine.
		3. Lock the previously assign forks, if there is just one philo, it exits the loop.
		4. Eat with its mutexes.
		5. Sleep.
		6. Think.
		7. Check if the simulation must to stop (following the monitor actions).
	Return (NULL) if the philo exits the while loop (used in functions that return a pointer *).
*/
void	*dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		check_full(philo);
		if (philo->full)
			return (NULL);
		lock_forks(philo);
		if (philo->table->nb_philos == 1)
			return (NULL);
		eat(philo);
		unlock_forks(philo);
		diazepam(philo);
		think(philo);
		pthread_mutex_lock(&philo->table->lock_bool_stop);
		if (philo->table->stop_flag)
		{
			pthread_mutex_unlock(&philo->table->lock_bool_stop);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->lock_bool_stop);
	}
	return (NULL);
}
