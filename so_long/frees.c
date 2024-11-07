/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:40:35 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 12:42:22 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_array(char **map_array, int map_line)
{
	while (map_line > 0)
	{
		free(map_array[map_line]);
		map_line--;
	}
	free(map_array);
	return (0);
}

void	ft_free_generate_failure(t_map *map)
{
	if (map -> array)
		free(map -> array);
	if (map -> copy)
		free(map -> copy);
	if (map -> file)
		free(map -> file);
	if (map -> line)
		free(map -> line);
	exit(EXIT_FAILURE);
}
