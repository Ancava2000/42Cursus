/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:11 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/21 10:57:07 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_array(char **array)
{
	int	line;

	line = 0;
	while (array[line])
	{
		free(array[line]);
		line++;
	}
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
	map -> height = i * 64;
}

int	ft_has_empty_lines(char *str)
{
	char	*end;

	end = 0;
	if (*str == '\0' || *str == '\n')
	{
		return (FALSE);
	}
	while (*str)
	{
		if (*(str + 1) == '\n' && *(str + 2) == '\n')
		{
			return (FALSE);
		}
		str++;
	}
	end = str + ft_strlen(str);
	if (*(end - 1) == '\n')
		return (FALSE);
	return (TRUE);
}

char	*ft_read_file(char *fn)
{
	int		fd;
	int		n;
	char	*temp;

	temp = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		free(temp);
		return (NULL);
	}
	n = read(fd, temp, BUFF_SIZE);
	if (n <= 0)
	{
		free(temp);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (temp);
}

char	**ft_read_map(char *fn)
{
	char	*temp;
	char	**array;

	temp = ft_read_file(fn);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	if (ft_has_empty_lines(temp))
	{
		free(temp);
		ft_printf(ERROR_NO_LINE);
		return (NULL);
	}
	array = ft_split(temp, '\n');
	if (!array)
		ft_free_array(array);
	free(temp);
	return (array);
}
