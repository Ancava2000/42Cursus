/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:28:25 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 12:57:57 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initializer(t_map *map, char **argv)
{
	map -> filename = argv[1];
	map -> moves = 0;
	map -> e = 0;
	map -> c = 0;
	map -> p = 0;
	map -> exit = 0;
	map -> player.x = 0;
	map -> player.y = 0;
	map -> y = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		ft_initializer(&map, argv);
		ft_map_check(&map);
		map.mlx = mlx_init(map.x * PIXEL, map.y * PIXEL, WND_NAME, true);
		map.wnd = mlx_new_window(map.mlx, map.x * PIXEL, map.y * PIXEL);
		ft_file_to_image(&map);
		ft_print_map(&map);
		mlx_hook(map.wnd, 17, 0, ft_destroy, &map);
		mlx_key_hook(map.wnd, ft_key_hook, &map);
		mlx_loop(map.mlx);
	}
	write(2, "ERROR\n", 6);
}
