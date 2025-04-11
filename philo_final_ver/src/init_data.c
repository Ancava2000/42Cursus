#include "../include/philo.h"

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
		philo->left_fork = &table->forks[i];
		if (philo->philo_id == table->nb_philos)
			philo->right_fork = &table->forks[0];
		else
			philo->right_fork = &table->forks[i + 1];
	}
	return (0);
}

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
