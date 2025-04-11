#include "../include/philo.h"

void	unlock_forks(t_philo *philo)
{
	if (philo->table->nb_philos % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		usleep(100);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		usleep(100);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	lock_forks(t_philo *philo, t_mutex *first_fork, t_mutex *second_fork)
{
	pthread_mutex_lock(first_fork);
	messages(1, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
	if (philo->table->nb_philos == 1)
	{
		precise_usleep(philo->table, philo->table->time_to_die);
		messages(5, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
		pthread_mutex_lock(&philo->table->lock_dead);
		philo->dead_status = 1;
		pthread_mutex_unlock(&philo->table->lock_dead);
		pthread_mutex_unlock(first_fork);
		return ;
	}
	pthread_mutex_lock(second_fork);
	messages(1, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
}

void	take_forks(t_philo *philo)
{
	t_mutex	*first_fork;
	t_mutex	*second_fork;

	if (philo->philo_id % 2 == 0)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	lock_forks(philo, first_fork, second_fork);
}
