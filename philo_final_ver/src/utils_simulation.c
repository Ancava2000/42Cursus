#include "../include/philo.h"

/*
	Funtion to print the actions messages:
		1. Assign lock_bool_stop mutex to new variable, shorter
		2. COndition depends on if the simulation it is stopped or not (decided by the waiter)
		3. Mutex to write.
		4. Messages formed by the string, the philo id and the time (get_current_time - time the dinner started).
*/
void	messages(int messages, unsigned int id, unsigned long long time, t_table *table)
{
	if (!table->stop_flag)
	{
		pthread_mutex_lock(&table->lock_write);
		if (messages == 1)
			printf(WHITE"%lu"RESET"%6d has taken a fork\n"RESET, time, id);
		else if (messages == 2)
			printf(WHITE"%lu"PINK"%6d is eating" "\t\t"WHITE"[%d]\n"RESET, time, id, table->philos->meals_eaten);
		else if (messages == 3)
			printf(WHITE"%lu"BLUE"%6d is sleeping\n"RESET, time, id);
		else if (messages == 4)
			printf(WHITE"%lu"GREEN"%6d is thinking\n"RESET, time, id);
		else if (messages == 5)
			printf(WHITE"%lu"PINK"%6d is full\n"RESET, time, id);
		else if (messages == 6)
			printf(WHITE"%lu"RED"%6d died\n"RESET, time, id);
		pthread_mutex_unlock(&table->lock_write);
	}
}

/*
	1. Free the memory allocated (philos and forks).
	2. Destroy every mutex.
*/
int	ft_clean(t_table *table)
{
	unsigned int	i;

	i = -1;
	if (table->philos)
		free(table->philos);
	if (table->forks)
	{
		while (++i < table->nb_philos)
		{
			if (pthread_mutex_destroy(&table->forks[i]))
				return (ft_error(RED"Error with pthread_mutex_destroy\n"RESET, 2), 1);
		}
		free(table->forks);
	}
	if (pthread_mutex_destroy(&table->lock_write) || pthread_mutex_destroy(&table->lock_dead)
		|| pthread_mutex_destroy(&table->lock_bool_stop)
		|| pthread_mutex_destroy(&table->lock_meal))
		return (ft_error(RED"Error with pthread_mutex_destroy\n"RESET, 2), 1);
	return (0);
}

/*
	Function to get the precise time in milliseconds.
		- tv.sec = seconds.
		- tv.usec = microseconds.
		- LL = long long.
*/
unsigned long long	get_now_time(void)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_error(RED"Error with gettimeofday\n"RESET, 2), 1);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}

/*
	1. If the time to eat or sleep is equal or greater than the time to die, we use the time to die (stopping the simulation).
		Ensures that the sleep never exceeds the time to die.
	2. If not, sleep that time * 1000 (just one millisecond).
	3. If there is an error, change the stop_flag to 1 so the simulation ends and returns -1 to indicate an error.
*/
long long	precise_usleep(t_table *table, unsigned long long time)
{
	if (time >= table->time_to_die)
		time = table->time_to_die;
	if (usleep(time * 1000))
	{
		ft_error(RED"Error with precise_usleep"RESET, 2);
		table->stop_flag = 1;
		return (-1);
	}
	return (0);
}
