#include "../include/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_meal);
	philo->last_eaten = get_now_time();
	pthread_mutex_unlock(&philo->table->lock_meal);
	precise_usleep(philo->table, philo->table->time_to_eat);
	pthread_mutex_lock(&philo->table->lock_meal);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->lock_meal);
}

void	diazepam(t_philo *philo)
{
	messages(3, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
	precise_usleep(philo->table, philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	messages(4, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
}

void	*dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		check_full(philo);
		if (philo->full)
			return (NULL);
		take_forks(philo);
		if (philo->table->nb_philos == 1)
			return (NULL);
		eat(philo);
		messages(2, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
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