/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:11:16 by kali              #+#    #+#             */
/*   Updated: 2025/04/05 08:29:34 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	ft_clean(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->philos->nb_philos)
	{
		pthread_mutex_destroy(&table -> philos[i].lock_philo);
	}
	pthread_mutex_destroy(&table->table_mutex->lock_write);
	pthread_mutex_destroy(&table->table_mutex->lock_meal);
}
*/
int	main(int ac, char **av)
{
	t_philo	philos[300];
	t_mutex	forks[300];
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parse_av(ac, av);
		init_table(&table, philos, forks, av);
		init_forks(&table, forks, ft_atoi2(av[1]));
		init_philos(&table, philos, forks, av);
		dinner(&table, philos[0].nb_philos);
		ft_clean(&table, philos[0].nb_philos);
	}
	else
		ft_error("Wrong number of arguments\n"
				GREEN "Correct is:\n5: nb of philos\n800: time to die\n200: time to eat\n200: time to sleep\n[5]: nb of meals\n"RESET, 1);
}
