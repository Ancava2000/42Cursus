#include "../include/philo.h"

/*
	Iterate each philo to check if they are dead, if one is dead,
	exits the function and the dinner routine, stopping the simulation.
		1. If check dead return 1 enters condition.
		2. stop = 1 and return 1. Indicating the monitor and the simulation to stop.
*/
int	check_all_dead(t_table *table)
{
	unsigned int	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		pthread_mutex_lock(&table->lock_dead);
		if (check_dead(table, i))
		{
			pthread_mutex_lock(&table->lock_bool_stop);
			table->stop_flag = 1;
			pthread_mutex_unlock(&table->lock_bool_stop);
			pthread_mutex_unlock(&table->lock_dead);
			return (1);
		}
		pthread_mutex_unlock(&table->lock_dead);
	}
	return (0);
}

/*
	Function to check if one philo is dead. If it is, returns 1
	and dead_status = 1 (to avoid entering full or dead function again).
		1. Dead_time = to calculate if the philo has time to eat before dying.
		2. If dead time is negative or 0, returns 1 and dead status = 1.
		3. Check if the philo is not full (if it's full the philo routine has stopped).
*/
int	check_dead(t_table *table, unsigned int i)
{
	unsigned long long dead_time;

	if (table->philos[i].dead_status)
		return (1);
	pthread_mutex_lock(&table->lock_meal);
	dead_time = table->philos[i].last_eaten - get_now_time() + table->time_to_die;
	if (dead_time <= 0 && !table->philos[i].full)
	{
		messages(6, i + 1, get_now_time() - table->dinner_start, table);
		table->philos[i].dead_status = 1;
		pthread_mutex_unlock(&table->lock_meal);
		return (1);
	}
	pthread_mutex_unlock(&table->lock_meal);
	return (0);
}

/*
	Function to check full state of each one of the philos. Increase i if philo[i] it's full (full = 1).
	If the value of i is = to nb_philos, stop = 1, exiting the waiter and, the dinner loop (all philos are full).
*/
void	check_all_full(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->lock_meal);
		if (table->philos[i].full)
			i++;
		else
		{
			pthread_mutex_unlock(&table->lock_meal);
			return ;
		}
		pthread_mutex_unlock(&table->lock_meal);
	}
	pthread_mutex_lock(&table->lock_bool_stop);
	if (i == table->nb_philos);
		table->stop_flag = 1;
	pthread_mutex_unlock(&table->lock_bool_stop);
	
}

/*
	Function to check if one philo is full and change the full variable to indicate it.
		1. Lock dead and meal mutex because those variables are being checked and changed.
		2. If the philo is dead or full, it exits the function (preventing them from unnecessary actions).
		3. If the number of meals_eaten == nb_meals, print message (full), full = 1 and exits the function. 
*/
void	check_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_dead);
	if (philo->dead_status || philo->full)
	{
		pthread_mutex_unlock(&philo->table->lock_dead);
		return ;
	}
	pthread_mutex_unlock(&philo->table->lock_dead);
	pthread_mutex_lock(&philo->table->lock_meal);
	if (philo->meals_eaten == philo->table->nb_meals)
	{
		messages(5, philo->philo_id, get_now_time() - philo->table->dinner_start, philo->table);
		philo->full = 1;
		pthread_mutex_unlock(&philo->table->lock_meal);
		return ;
	}
	pthread_mutex_unlock(&philo->table->lock_meal);
}

/*
	Monitor function:
		1. The function checks the dead and full status while the stop_flag is 0. If one philo is dead or all are full, stop = 1 and the monitoring stop.
		2. One philo isn't allowed, case already covered in forks.c.
		3. If there is one philo or one dead, break ; exiting the loop and the function (return NULL).
		4. Check if all the philos are full.
*/
void	*waiter(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while(!table->stop_flag)
	{
		if (table->nb_philos == 1 || check_all_dead(table))
			break ;
		check_all_full(table);
		usleep(10);
	}
	return (NULL);
}
