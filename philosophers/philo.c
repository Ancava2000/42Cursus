/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:13:09 by acarro-v          #+#    #+#             */
/*   Updated: 2025/04/02 14:06:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_table *table)
{
	int i;

	i = -1;
	while (++i < table -> nb_philos)
	{
		pthread_mutex_destroy(&table -> philos[i].lock_philo);
	}
	free(table -> philos);
	free(table -> forks);
	pthread_mutex_destroy(&table -> lock_write);
	pthread_mutex_destroy(&table -> lock_simulation);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parse_av(&table, av);
		init_data(&table);
		launcher(&table);
		ft_clean(&table);
	}
	else
	{
		ft_error_2();
		ft_error("Wrong number of arguments");
	}
}
