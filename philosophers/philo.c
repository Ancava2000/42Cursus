/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:13:09 by acarro-v          #+#    #+#             */
/*   Updated: 2025/03/27 08:43:31 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_table *table)
{
	int i;

	i = -1;
	while (++i < table -> nb_philos)
	{
		pthread_mutex_destroy(&table -> philos[i].left_fork);
		pthread_mutex_destroy(&table -> philos[i].right_fork);
	}
	free(table -> philos);
	free(table -> forks);
	pthread_mutex_destroy(&table -> lock_write);
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
