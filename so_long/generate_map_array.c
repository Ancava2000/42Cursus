/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:22:23 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 12:27:51 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_map *map)
{
	int	fd;

	map -> y = 0;
	map -> line = " ";
	map -> file = NULL;
	fd = open(map -> filename, O_RDONLY);
	if (fd == -1)
		ft_error_no_file();
	while (map -> line)
	{
		map -> line = get_next_line(fd);
		if (map -> line == NULL)
			break ;
		map -> file = ft_strjoin(map -> file, map -> line);
		free(map -> line);
		if (!map -> file)
			ft_free_generate_failure(map);
		map -> y++;
	}
	map -> array = ft_split(map -> file, '\n');
	map -> copy = ft_split(map -> file, '\n');
	if (!map -> array || !map -> copy)
		ft_free_generate_failure(map);
	free(map -> file);
}
