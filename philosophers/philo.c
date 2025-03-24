/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:13:09 by acarro-v          #+#    #+#             */
/*   Updated: 2025/03/24 14:24:06 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (av == 5)
	{
		parse(&table, **av);
		init_data(&table);
		launcher(&table);
		ft_clean(&table);
	}
	else
		ft_error("Wrong number of arguments");
}
