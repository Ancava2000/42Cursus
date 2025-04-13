#include "../include/philo.h"

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

/*
	1. Lock the first and second fork with their respective messages (previously assign to avoid deadlocks).
	2. Do the single philosopher case:
		- Fork message.
		- Sleep the time to die.
		- Dead message.
		- Change dead status to 1 for the waiter function (to indicate that the philosopher is dead and stop the simulation).
		- Unlock dead and for mutex.
		- Return ; to exit the function (return ; used in void functions to exit directly).
*/
void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	messages(1, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
	if (philo->table->nb_philos == 1)
	{
		precise_usleep(philo->table, philo->table->time_to_die);
		messages(6, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
		pthread_mutex_lock(&philo->table->lock_dead);
		philo->dead_status = 1;
		pthread_mutex_unlock(&philo->table->lock_dead);
		pthread_mutex_unlock(philo->first_fork);
		return ;
	}
	pthread_mutex_lock(philo->second_fork);
	messages(1, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
}
