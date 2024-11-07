/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:57:10 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:25 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_floor(t_map *map, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (map -> array[y])
	{
		x = 0;
		while (map -> array[x])
		{
			mlx_image_to_window(map -> mlx, image -> floor, x * 32, y * 32);
			if (map -> array[y][x] == '1')
				mlx_image_to_window(map-> mlx, image -> wall, x * 32, y * 32);
			if (map -> array[y][x] == 'E')
			{
				mlx_image_to_window(map -> mlx, image->close_exit,
					x * 32, y * 32);
				mlx_image_to_window(map -> mlx, image->open_exit,
					x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	ft_print_elements(t_map *map, t_images *image)
{
	int	x;
	int	y;

	ft_print_floor(map, image);
	y = 0;
	while (map -> array[y])
	{
		x = 0;
		while (map -> array[x])
		{
			if (map -> array[y][x] == 'C')
				mlx_image_to_window(map-> mlx, image -> collectible,
					x * 32, y * 32);
			if (map -> array[y][x] == 'P')
				mlx_image_to_window(map-> mlx, image -> player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
/*
void	ft_print_moves(t_map *map)
{
	char	*moves;

	moves = atoi(map -> moves);
	write(1, "You have made: ", 20);
	write(1, moves, ft_strlen(moves));
	write(1, " moves\n", 20);
	free(moves);
}
*/