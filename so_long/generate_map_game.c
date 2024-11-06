/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:57:10 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 14:54:27 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_elements(t_map *map, int x, int y)
{
	int	y;
}

void	ft_print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map -> y)
	{
		while (x < map -> x)
		{
			ft_print_elements(map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_print_moves(t_map *map)
{
	char	*moves;

	moves = atoi(map -> moves);
	write(1, "You have made: ", 20);
	write(1, moves, ft_strlen(moves));
	write(1, " moves\n", 20);
	free(moves);
}
