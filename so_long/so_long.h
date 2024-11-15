/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:23:40 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 16:03:45 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;91m" 
# define CYAN "\033[1;96m"
# define BLUE "\033[0;34m" 
# define PINK "\e[95m"
# define RESET "\033[0m"

# define FALSE	1
# define TRUE	0
# define MOVE	64
# define BUFF_SIZE 10000

# define ERROR_PARAM RED "Error\nIncorrect number of parameters\n" RESET
# define ERROR_BER RED "Error\nFile has invalid file extension\n" RESET
# define ERROR_EMPTY RED "Error\nMap is empty\n" RESET
# define ERROR_RECT RED "Error\nMap is not rectangle.\n" RESET
# define ERROR_WRONG_COLLECT RED "Error\nMap have the wrongs components\n" RESET
# define ERROR_WALL RED "Error\nMap don't have close walls\n" RESET
# define ERROR_NB_COLLECT RED "Error\nYou don't have the correct components\n" RESET
# define ERROR_PATH RED RED "Error\nThere is not a valid path\n" RESET

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "Libft/inc/libft/libft.h"

//estructura texturas
typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*open_exit;
	mlx_texture_t	*close_exit;
	mlx_texture_t	*player;
}	t_texture;

//estructura imágenes
typedef struct s_image
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
	mlx_image_t		*open_exit;
	mlx_image_t		*close_exit;
}	t_image;

//estructura datos del mapa
//Widht = y 
//Height = x
typedef struct s_map
{
	struct s_texture	*textu;
	struct s_image		*img;
	mlx_image_t			**exit_image;
	mlx_image_t			*wnd_moves;
	mlx_t				*mlx;
	char				**array;
	char				**copy;
	int					width;
	int					height;
	int					c_moves;
	int					c_collectible;
	int					t_collectible;
}	t_map;

int		main(int argc, char **argv);
void	ft_size_map(t_map *map, char **array);
char	**ft_read_map(char *fn);
int		ft_map_check(char **array);
int		ft_check_ber(char *fn);
int		ft_min_elements(char **array);
void	ft_get_textures(t_map *map);
void	ft_get_images(t_map *map);
void	ft_delete_textu(t_map *map);
void	ft_print_elements(t_map *map, t_image *image);
void	ft_print_floor(t_map *map, t_image *image);
//void	ft_render_exit(int y, int x, t_map *map);
//void	ft_close_exits(t_map *map);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_count_collectibles(t_map *map);
int		ft_total_collectibles(t_map *map);
void	ft_check_win(t_map *map);
void	ft_moves(t_map *map);
void	ft_free_array(char **array);

#endif