/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:31:33 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/07 16:04:56 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_textures(t_map *map)
{
	map ->textu = ft_calloc(1, sizeof(t_textures));
	map->textu->floor = mlx_load_png("/resources/floor.png");
	map-> textu->wall = mlx_load_png("/resources/wall.png");
	map-> textu->collectible = mlx_load_png("/resources/cat.png");
	map->textu->player = mlx_load_png("/resources/mago.png");
	map ->textu->close_exit = mlx_load_png("/resources/close_exit.png");
	map ->textu->open_exit = mlx_load_png("/resources/open_exit.png");
}

void	ft_get_images(t_map *map)
{
	map->img = ft_calloc(1, sizeof(t_images));
	map->img->floor = mlx_texture_to_image(map->mlx, map->textu->floor);
	map->img->wall = mlx_texture_to_image(map->mlx, map->textu->wall);
	map->img->collectible = mlx_texture_to_image(map->mlx,
			map->textu->collectible);
	map->img->player = mlx_texture_to_image(map->mlx, map->textu->player);
	map->img->close_exit = mlx_texture_to_image(map->mlx,
			map->textu->close_exit);
	map->img->open_exit = mlx_texture_to_image(map->mlx, map->textu->open_exit);
	mlx_delete_texture(map->textu->floor);
	mlx_delete_texture(map->textu->wall);
	mlx_delete_texture(map->textu->collectible);
	mlx_delete_texture(map->textu->player);
	mlx_delete_texture(map->textu->close_exit);
	mlx_delete_texture(map->textu->open_exit);
}
