/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:06:21 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 15:28:09 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_empty_map(char **array)
{
	if (array[0])
		return (TRUE);
	else
		return (FALSE);
}

int	ft_check_rectangle(char **array)
{
	size_t	len;
	int		y;

	len = ft_strlen(array[0]);
	y = 1;
	while (array[y])
	{
		if (ft_strlen(array[y]) != len)
			return (FALSE);
		else
			y++;
	}
	return (TRUE);
}

int	ft_check_content(char **array)
{
	int	y;
	int	x;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (!(array[y][x] == '0' || array[y][x] == '1' ||
				array[y][x] == 'C' || array[y][x] == 'P' ||
				array[y][x] == 'E'))
				return (FALSE);
			else
				x++;
		}
		y++;
	}
	return (TRUE);
}

int	ft_check_walls(char **array)
{
	size_t	y;
	size_t	x;
	size_t	line;

	line = 0;
	while (array[line])
		line++;
	x = 0;
	while (x < ft_strlen(array[0]))
	{
		if (array[0][x] != '1' || array[line - 1][x] != '1')
			return (FALSE);
		x++;
	}
	y = 0;
	while (y < line)
	{
		row = ft_strlen(array[y]);
		if (array[y][0] != '1' || array[y][row - 1] != '1')
			return (FALSE);
		y++;
	}
	return (TRUE);
}

int	ft_map_check(char **array)
{
	if (ft_empty_map(array) == FALSE)
		return (ft_printf(ERROR_EMPTY), FALSE);
	if (ft_check_rectangle(array) == FALSE)
		return (ft_printf(ERROR_RECT), FALSE);
	if (ft_check_content(array) == FALSE)
		return (ft_printf(ERROR_WRONG_COLLECT), FALSE);
	if (ft_check_walls(array) == FALSE)
		return (ft_printf(ERROR_WALL), FALSE);
	if (ft_min_elements(array) == FALSE)
		return (ft_printf(ERROR_NB_COLLECT), FALSE);
	return (TRUE);
}
