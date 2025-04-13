#include "../include/philo.h"

/*
	Initialize mutex:
		1. There are multiple forks, allocate each one of them.
		2. Initialize each fork mutex.
		3. Initialize all the locks mutex.
*/
int	init_mutex(t_table *table)
{
	unsigned int	i;

	i = -1;
	if (!(table->forks = malloc(sizeof(t_mutex) * table->nb_philos)))
	{
		ft_clean(table);
		return (ft_error(RED"Error malloc forks\n"RESET, 2), 1);
	}
	while (++i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			ft_clean(table);
			return (ft_error(RED"Error init forks\n"RESET, 2), 1);
		}
	}
	if (pthread_mutex_init(&table->lock_write, NULL) || pthread_mutex_init(&table->lock_dead, NULL)
		|| pthread_mutex_init(&table->lock_bool_stop, NULL)
		|| pthread_mutex_init(&table->lock_meal, NULL))
	{
		ft_clean(table);
		return (ft_error(RED"Error init mutex\n"RESET, 2), 1);
	}
	return (0);
}

/*
	For each philo we initialize each variable of the struct.
	To avoid deadlocks, we assign the forks depending on the philo_id
*/
int	init_philos(t_table *table)
{
	unsigned int	i;
	t_philo			*philo;

	i = -1;
	while (++i < table->nb_philos)
	{
		philo = table->philos + i;
		philo->philo_id = i + 1;
		philo->meals_eaten = 0;
		philo->dead_status = 0;
		philo->full = 0;
		philo->last_eaten = table->dinner_start;
		philo->table = table;
        philo->first_fork = &table->forks[i];
        philo->second_fork = &table->forks[(i + 1) % table->nb_philos];
        if (philo->philo_id % 2 == 0)
        {
            philo->first_fork = &table->forks[(i + 1) % table->nb_philos];
            philo->second_fork = &table->forks[i];
        }
	}
	return (0);
}

/*
	Create one thread for each philo, doing the dinner function.
	Create the monitor thread.
	Join all the threads to create the loop.
*/
int	init_threads(t_table *table)
{
	unsigned int	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i].philo_thread, NULL, &dinner, &table->philos[i]))
		{
			ft_clean(table);
			return (ft_error(RED"Error init threads\n"RESET, 2), 1);
		}
	}
	if (pthread_create(&table->waiter, NULL, &waiter, table))
	{
		ft_clean(table);
		return (ft_error(RED"Error init threads\n"RESET, 2), 1);
	}
	pthread_join(table->waiter, NULL);
	i = -1;
	while (++i < table->nb_philos)
		pthread_join(table->philos[i].philo_thread, NULL);
	return (0);
}

/*
	Initialize all the data of the table:
		1. Convert and assign parameters to variables.
		2. Deal with number of meals.
		3. There are multiple philos, allocate each one of them.
	Initialize mutex, philos and threads.
*/
int	init_dinner(t_table *table, int ac, char **av)
{
	table->philos = NULL;
	table->nb_philos = atoi_int(av[1]);
	table->time_to_die = atoi_ll(av[2]);
	table->time_to_eat = atoi_ll(av[3]);
	table->time_to_sleep = atoi_ll(av[4]);
	table->dinner_start = get_now_time();
	if (ac == 6)
		table->nb_meals = atoi_int(av[5]);
	else
		table->nb_meals = -1;
	if (!(table->philos = malloc(sizeof(t_philo) * table->nb_philos)))
	{
		ft_clean(table);
		return (ft_error(RED"Error during malloc\n"RESET, 2), 1);
	}
	if (init_mutex(table))
		return (1);
	if (init_philos(table))
		return (1);
	if (init_threads(table))
		return (1);
	return (0);
}
