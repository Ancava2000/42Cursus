/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:18:35 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/07 15:51:50 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_map *map)
{
	map -> exit = 1;
	map -> moves++;
	mlx_clear_window(map -> mlx, 0xFF000000);
	mlx_string_put(map -> mlx, 10, 10, 0xFFFFFF, "YIPPIE!");
	write(1, "YOU WIN!", 20);
}
