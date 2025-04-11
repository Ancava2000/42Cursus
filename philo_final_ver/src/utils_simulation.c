#include "../include/philo.h"

void	messages(int messages, unsigned int id, unsigned long long time, t_table *table)
{
	bool	stop;

	pthread_mutex_lock(&table->lock_bool_stop);
	stop = table->stop_flag;
	pthread_mutex_unlock(&table->lock_bool_stop);
	if (!stop)
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

unsigned long long	get_now_time(void)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_error(RED"Error with gettimeofday\n"RESET, 2), 1);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}

unsigned long long	precise_usleep(t_table *table, unsigned long long time)
{
	if (time >= table->time_to_die)
		time = table->time_to_die;
	if (usleep(time * 1000))
	{
		ft_error(RED""RESET, 2);
		table->stop_flag = 1;
		return (-1);
	}
	return (0);
}
