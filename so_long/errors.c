/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:43:05 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 12:46:14 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_extension(void)
{
	write(2, "Wrong extension, should be .ber", 20);
	exit(EXIT_FAILURE);
}

void	ft_error_no_file(void)
{
	write(2, "Couldn't open file", 20);
	exit(EXIT_FAILURE);
}

void	ft_error_rectangle(t_map *map)
{
	write(2, "The map is not a rectangle", 20);
	free_array(map -> array, map -> y);
	free_array(map -> copy, map -> y);
	exit(EXIT_FAILURE);
}

void	ft_error_walls(t_map *map)
{
	write(2, "The walls are not correct", 20);
	free_array(map -> array, map -> y);
	free_array(map -> copy, map -> y);
	exit(EXIT_FAILURE);
}

void	ft_error_content(t_map *map)
{
	write(2, "There's an incorrect number of elements", 20);
	free_array(map -> array, map -> y);
	free_array(map -> copy, map -> y);
	exit(EXIT_FAILURE);
}
