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

#include "so_long_bonus.h"

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

int	*ft_scan_player(char **copy)
{
	int	y;
	int	x;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	ft_flood_fill(t_map *map, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= map -> width || y >= map -> height
			|| map -> copy[y][x] == '1' || map -> copy[y][x] == '*'))
	{
		map -> copy[y][x] = '*';
		ft_flood_fill(map, y + 1, x);
		ft_flood_fill(map, y - 1, x);
		ft_flood_fill(map, y, x + 1);
		ft_flood_fill(map, y, x - 1);
	}
}

int	ft_check_flood(char **copy)
{
	int	y;
	int	x;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (!(copy[y][x] == '1' || copy[y][x] == '0'
				|| copy[y][x] == '*'))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	ft_check_path(t_map *map, char *fn)
{
	int	*pos;

	map -> copy = ft_read_map(fn);
	pos = ft_scan_player(map -> copy);
	if (!(pos))
	{
		free(pos);
		return (1);
	}
	ft_flood_fill(map, pos[0], pos[1]);
	if (ft_check_flood(map -> copy) == FALSE)
	{
		free(pos);
		ft_free_array(map -> copy);
		return (ft_printf(ERROR_PATH), FALSE);
	}
	free(pos);
	ft_free_array(map -> copy);
	return (TRUE);
}
