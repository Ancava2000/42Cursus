/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:36 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/07 16:09:18 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WND_NAME "so_long"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

//estructura texturas
typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*character;
	mlx_texture_t	*open_exit;
	mlx_texture_t	*close_exit;
	mlx_texture_t	*enemy;
	mlx_texture_t	*player;
}	t_textures;

//estructura imganes
typedef struct s_images
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectible;
	mlx_image_t		*character;
	mlx_image_t		*open_exit;
	mlx_image_t		*close_exit;
	mlx_image_t		*enemy;
	mlx_image_t		*player;
}	t_images;

//estructura datos del mapa
typedef struct s_map
{
	int					fd;
	char				*filename;
	char				*line;
	char				*file;
	char				**array;
	char				**copy;
	int					moves;
	int					x;
	int					y;
	int					e;
	int					c;
	int					p;
	int					exit;
	int					c_check;
	int					e_check;
	mlx_t				*mlx;
	struct s_images		*img;
	struct s_textures	*textu;
	t_player			player;
}	t_map;

//Checkers
void	ft_map_check(t_map *map);

//Array
void	ft_read_map(t_map *map);

//Errors
void	ft_error_extension(void);
void	ft_error_no_file(void);
void	ft_error_rectangle(t_map *map);
void	ft_error_walls(t_map *map);
void	ft_error_content(t_map *map);

//Free
int		ft_free_array(char **map_array, int map_line);
void	ft_free_generate_failure(t_map *map);

//Images
void	ft_file_to_image(t_map *map);

//Generate game
void	ft_print_elements(t_map *map, int x, int y);
void	ft_print_map(t_map *map);

//End screen
int		ft_destroy(t_map *map);

#endif