/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:17:30 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 16:05:22 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_floor(t_map *map, t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (map -> array[y])
	{
		x = 0;
		while (map -> array[y][x])
		{
			mlx_image_to_window(map -> mlx, image -> floor, x * 64, y * 64);
			if (map -> array[y][x] == '1')
				mlx_image_to_window(map-> mlx, image -> wall, x * 64, y * 64);
			if (map -> array[y][x] == 'E')
			{
				mlx_image_to_window(map->mlx, image->open_exit, x * 64, y * 64);
				mlx_image_to_window(map->mlx,
					image->close_exit, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	ft_print_elements(t_map *map, t_image *image)
{
	int	x;
	int	y;

	ft_print_floor(map, image);
	y = 0;
	while (map -> array[y])
	{
		x = 0;
		while (map -> array[y][x])
		{
			if (map -> array[y][x] == 'C')
				mlx_image_to_window(map-> mlx, image -> collectible,
					x * 64, y * 64);
			if (map -> array[y][x] == 'P')
				mlx_image_to_window(map-> mlx, image -> player,
					x * 64, y * 64);
			if (map -> array[y][x] == 'A')
				mlx_image_to_window(map-> mlx, image -> alien,
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}
