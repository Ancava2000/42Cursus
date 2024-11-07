/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:22 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/07 15:18:21 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(const char *filename)
{
	size_t	line;

	line = ft_strlen(filename - 1);
	if (filename[line] != 'r' || filename[line - 1] != 'e'
		|| filename[line - 2] != 'b'
		|| filename[line - 4] != '.')
		return (1);
	return (0);
}

void	ft_check_rectangle(t_map *map)
{
	int	x;
	int	y;
	int	line_length;

	x = 0;
	y = 0;
	line_length = strlen(map -> array[y]);
	while (y < map-> y)
	{
		x = strlen(map -> array[y]);
		if (line_length != x)
			ft_error_rectangle(map);
		y++;
	}
	x = line_length;
}

void	ft_check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map -> array[0][x] == '1' && map -> array[1][x])
		x++;
	if (map -> array[1][0] != '\0')
		ft_error_walls(map);
	y = 1;
	while (y < map -> y)
	{
		if (map -> array[y][x] != '1' || map -> array[y][x - 1] != '1')
			fr_error_walls(map);
		y++;
	}
	x = 0;
	while (map -> array[y - 1][x] == '1')
		x++;
	if (map -> array[y - 1][x] != '\0')
		ft_error_walls(map);
}

void	ft_check_content(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map -> y)
	{
		while (x < map -> x)
		{
			if (map -> array[y][x] == 'C')
				map -> c += 1;
			else if (map -> array[y][x] == 'E')
				map -> e += 1;
			else if (map -> array[y][x] == 'P')
				map -> p += 1;
			else if (map -> array[y][x] == '0' || map -> array[y][x] == '1')
				;
			else
				ft_error_content(map);
			x++;
		}
		x = 0;
		y++;
	}
	if (map -> c < 1 || map -> e != 1 || map -> p != 1)
		ft_error_content(map);
}

void	ft_map_check(t_map *map)
{
	ft_read_map(map);
	ft_check_rectangle(map);
	ft_check_walls(map);
	ft_check_content(map);
	ft_check_valid_exit(map);
	size_map(&map, map -> array);
	ft_free_array(map -> copy, map -> y);
}
