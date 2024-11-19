/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endscreen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:23:01 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 15:47:49 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moves(t_map *map)
{
	char	*mov;

	if (map -> wnd_moves)
		mlx_delete_image(map -> mlx, map -> wnd_moves);
	mov = ft_itoa(map -> c_moves);
	map -> wnd_moves = mlx_put_string(map -> mlx, mov, 46, 50);
	free (mov);
}


void	ft_check_ending(t_map *map)
{
	if (map -> c_collectible == map -> t_collectible)
	{
		mlx_close_window(map -> mlx);
		ft_printf(CYAN "CONGRATULATIONS, YOU WON!\n"RESET);
	}
	else
		ft_printf(BLUE"The door is closed...\n"RESET);
}
