/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:28:25 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/07 16:06:13 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initializer(t_map *map)
{
	map -> moves = 0;
	map -> e = 0;
	map -> c = 0;
	map -> p = 0;
	map -> exit = 0;
	map -> player.x = 0;
	map -> player.y = 0;
	map -> y = 0;
	ft_map_check(map);
	map -> mlx = mlx_init(map -> x, map -> y, WND_NAME, false);
	ft_get_textures(map);
	ft_get_images(map);
	ft_print_elements(map, map->img);
	mlx_key_hook(map -> mlx, &ft_key_hook, map);
	mlx_loop(map -> mlx);
	mlx_terminate(map->mlx);
	ft_free_array(map -> array, map -> y);
	free(map->textu);
	free(map->img);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		write (2, "Input only 2 arguments", 20);
	else if (argc == 2)
	{
		if (ft_check_ber(argv[1]))
			ft_error_extension();
		ft_initializer(&map);
	}
	return (0);
}
