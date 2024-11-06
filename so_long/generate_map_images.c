/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:31:33 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 16:17:57 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_to_image(t_map *map)
{
	int	a;

	a = PIXEL;
	map -> img.floor = mlx_xpm_file_to_image(map -> mlx,
			"dirección de textura", &a, &a);
	map -> img.wall = mlx_xpm_file_to_image(map -> mlx,
			"dirección de textura", &a, &a);
	map -> img.collectible = mlx_xpm_file_to_image(map -> mlx,
			"/resources/cat.xpm", &a, &a);
	map -> img.close_exit = mlx_xpm_file_to_image(map -> mlx,
			"dirección de textura", &a, &a);
	map -> img.enemy = mlx_xpm_file_to_image(map -> mlx,
			"dirección de textura", &a, &a);
	map -> img.player = mlx_xpm_file_to_image(map -> mlx,
			"dirección de textura", &a, &a);
}
