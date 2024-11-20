/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:05:39 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 15:31:48 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_initialize(t_map *map)
{
	map -> c_moves = 0;
	map -> c_collectible = 0;
	map -> mlx = mlx_init(map -> width, map -> height, "so_long", false);
	if (!(map -> mlx))
		return (FALSE);
	ft_get_textures(map);
	ft_get_images(map);
	ft_print_elements(map, map -> img);
	mlx_key_hook(map -> mlx, &ft_key_hook, map);
	mlx_loop(map -> mlx);
	mlx_terminate(map -> mlx);
	ft_free_array(map -> array);
	free(map -> textu);
	free(map -> img);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_printf(ERROR_PARAM), 1);
	if (ft_check_ber(argv[1]) == FALSE)
		return (ft_printf(ERROR_BER), 1);
	map.array = ft_read_map(argv[1]);
	if (!map.array)
		return (1);
	if (ft_map_check(map.array) == FALSE)
		return (ft_free_array(map.array), 1);
	ft_size_map(&map, map.array);
	if (ft_check_valid_exit(&map, argv[1]) == FALSE)
		return (ft_free_array(map.array), 1);
	if (ft_initialize(&map) == FALSE)
		return (1);
	return (0);
}
