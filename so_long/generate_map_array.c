/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:11 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 16:04:35 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_array(char **array)
{
	int	line;

	line = -1;
	while (array[++line])
		free(array[line]);
	free(array);
}

void	ft_size_map(t_map *map, char **array)
{
	int	i;

	i = 0;
	map -> t_collectible = ft_total_collectibles(map);
	map -> width = ft_strlen(array[0]) * 64;
	while (array[i])
		i++;
	map-> height = i * 64;
}

char	**ft_read_map(char *fn)
{
	int		fd;
	int		n;
	char	*temp;
	char	**array;

	n = 0;
	temp = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp)
		return (0);
	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		free(temp);
		return (0);
	}
	n = read(fd, temp, BUFF_SIZE);
	if (n == -1 || n == 0)
	{
		free(temp);
		return (0);
	}
	array = ft_split(temp, '\n');
	free(temp);
	close(fd);
	return (array);
}
