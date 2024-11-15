/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:08:02 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 15:29:43 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'r' || fn[i - 1] != 'e'
		|| fn[i - 2] != 'b'
		|| fn[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

int	ft_min_elements(char **array)
{
	int	y;
	int	x;
	int	nb_exit;
	int	nb_collect;

	y = 0;
	nb_exit = 0;
	nb_collect = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'E' || array[y][x] == 'P')
				nb_exit++;
			if (array[y][x] == 'C')
				nb_collect++;
			x++;
		}
		y++;
	}
	if (nb_exit != 2 || nb_collect < 1)
		return (FALSE);
	return (TRUE);
}
