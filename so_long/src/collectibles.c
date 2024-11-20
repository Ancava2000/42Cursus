/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:18:54 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 16:03:41 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_total_collectibles(t_map *map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	while (map -> array[y])
	{
		x = 0;
		while (map -> array[y][x])
		{
			if (map -> array[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_delete_collect(t_map *map)
{
	int	i;
	int	total;

	i = 0;
	total = map -> t_collectible;
	while (i < total)
	{
		if (((map -> img -> collectible -> instances[i].y
					== map -> img -> player -> instances -> y)
				&& (map -> img -> collectible -> instances[i].x
					== map -> img -> player -> instances -> x)
				&& (map -> img -> collectible -> instances[i].enabled == true)))
		{
			total--;
			map -> img -> collectible -> instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	ft_count_collectibles(t_map *map)
{
	if (map -> array [map -> img -> player -> instances -> y / 64]
		[map -> img -> player -> instances -> x / 64] == 'C')
	{
		ft_delete_collect(map);
		map -> array [map -> img -> player -> instances -> y / 64]
		[map -> img -> player -> instances -> x / 64] = '0';
		map -> c_collectible++;
		ft_printf(BLUE"%i Jonesy saved!\n"RESET, map -> c_collectible);
		if (map -> c_collectible == map -> t_collectible)
		{
			map -> img -> close_exit -> instances -> enabled = false;
			ft_printf(BLUE"You have collected all cats!\n"RESET);
		}
	}
	if (map -> array[map ->img->player->instances->y / 64]
		[map ->img->player->instances->x / 64] == 'E')
		ft_check_ending(map);
}
