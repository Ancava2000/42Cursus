#include "../include/philo.h"

/*
	1. Checks correct and positive numbers.
	2. Converts those numbers and assign them to temporal variables.
	3. If there is a number of meals it is assign.
	4. Uses those temporal variables to check for other errors (nb_meals <= 0 || < 1).
*/
int	parsing(int ac, char **av)
{
	int			nb_philos;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int			nb_meals;

	nb_philos = atoi_int(av[1]);
	time_to_die = atoi_ll(av[2]);
	time_to_eat = atoi_ll(av[3]);
	time_to_sleep = atoi_ll(av[4]);
	nb_meals = 0;
	if (ac == 6)
	{
		nb_meals = atoi_int(av[5]);
		if (nb_meals == 0 || nb_meals < 0)
			return (ft_error(RED"Indicate at least 1 meal\n"RESET, 2), 1);
	}
	if (nb_philos < 1 || time_to_die < 1 || time_to_eat < 1
		|| time_to_sleep < 1)
		return (ft_error(RED"Indicate more than 1 in arguments\n"RESET, 2), 1);
	return (0);
}
/*	
	1. Check nb of parameters.
	2. Parsing (Check all positive numbers and converts to int or long long).
	3. Assign and initialize all the data (variable, mutex and threads) and start simulation.
	4. Clean mallocs and mutex.
*/
int	main(int ac, char **av)
{
	t_table			table;
	unsigned int	i;

	table.stop_flag = 0;
	if (ac < 5 || ac > 6)
		return (ft_error(RED"Incorrect number of arguments\n"RESET, 2), 1);
	i = parsing(ac, av);
	if (i == 1)
		return (1);
	if (init_dinner(&table, ac, av))
		return (1);
	return (ft_clean(&table));
}
