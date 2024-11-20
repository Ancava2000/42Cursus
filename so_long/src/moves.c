/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:18:17 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 16:03:44 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_map *map)
{
	if (map -> array[map -> img -> player -> instances -> y / 64 - 1]
		[map -> img -> player -> instances -> x / 64] != '1')
	{
		map -> img -> player -> instances -> y -= MOVE;
		map -> c_moves++;
		ft_printf(PINK"You have made: %i move/s\n"RESET, map->c_moves);
	}
}

void	ft_move_right(t_map *map)
{
	if (map -> array[map -> img -> player -> instances -> y / 64]
		[map -> img -> player -> instances -> x / 64 + 1] != '1')
	{
		map -> img -> player -> instances -> x += MOVE;
		map -> c_moves++;
		ft_printf(PINK"You have made: %i move/s\n"RESET, map->c_moves);
	}
}

void	ft_move_down(t_map *map)
{
	if (map -> array[map -> img -> player -> instances -> y / 64 + 1]
		[map -> img -> player -> instances -> x / 64] != '1')
	{
		map -> img -> player -> instances -> y += MOVE;
		map -> c_moves++;
		ft_printf(PINK"You have made: %i move/s\n"RESET, map->c_moves);
	}
}

void	ft_move_left(t_map *map)
{
	if (map -> array[map -> img -> player -> instances -> y / 64]
		[map -> img -> player -> instances -> x / 64 - 1] != '1')
	{
		map -> img -> player -> instances -> x -= MOVE;
		map -> c_moves++;
		ft_printf(PINK"You have made: %i move/s\n"RESET, map->c_moves);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		ft_move_up(map);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		ft_move_right(map);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		ft_move_down(map);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		ft_move_left(map);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(map->mlx);
	ft_count_collectibles(map);
}
