/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:44:28 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/19 12:59:17 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_alien(t_map *map)
{
	if (map -> array [map -> img -> player -> instances -> y / 64]
		[map -> img -> player -> instances -> x / 64] == 'A')
	{
		if (((map -> img -> alien -> instances -> y
					== map -> img -> player -> instances -> y)
				&& (map -> img -> alien -> instances -> x
					== map -> img -> player -> instances -> x)
				&& (map -> img -> player -> instances -> enabled == true)))
		{
			map -> img -> player -> instances -> enabled = false;
			map -> c_moves++;
			mlx_close_window(map -> mlx);
			ft_printf(CYAN "OH NO!\n"RESET);
		}
	}
}
