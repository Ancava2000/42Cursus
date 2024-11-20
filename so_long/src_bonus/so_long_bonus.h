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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// COLORS
# define RED "\033[1;91m" 
# define CYAN "\033[1;96m"
# define BLUE "\033[0;34m" 
# define PINK "\e[95m"
# define RESET "\033[0m"

# define FALSE	1
# define TRUE	0
# define MOVE	64
# define BUFF_SIZE 10000

// ERROR MESSAGES
# define ERROR_PARAM "\033[1;91mError\nIncorrect number of parameters\n\033[0m"
# define ERROR_BER  "\033[1;91mError\nFile has invalid file extension\n\033[0m"
# define ERROR_NO_LINE  "\033[1;91mError\nMap has an empty line\n\033[0m" 
// # define ERROR_EMPTY  "\033[1;91mError\nMap is empty\n\033[0m" 
# define ERROR_RECT "\033[1;91mError\nMap is not a rectangle.\n\033[0m" 
# define ERROR_WRONG_COL "\033[1;91mError\nWrongs components\n\033[0m"
# define ERROR_WALL  "\033[1;91mError\nMap doesn't have close walls\n\033[0m" 
# define ERROR_NB_COL "\033[1;91mError\nIncorrect number of components\n\033[0m"
# define ERROR_PATH "\033[1;91mError\nThere is not a valid path\n\033[0m"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/inc/libft/libft.h"

//textures
typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*open_exit;
	mlx_texture_t	*close_exit;
	mlx_texture_t	*player;
	mlx_texture_t	*alien;
}	t_texture;

//images
typedef struct s_image
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
	mlx_image_t		*open_exit;
	mlx_image_t		*close_exit;
	mlx_image_t		*alien;
}	t_image;

//map data
//Width = y 
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
	int					c_collectible; //what the player has
	int					t_collectible; //the total
}	t_map;

// Main an initialization
int		main(int argc, char **argv);
// Read map and checkers map
int		ft_check_ber(char *fn);
char	**ft_read_map(char *fn);
int		ft_map_check(char **array);
void	ft_size_map(t_map *map, char **array);
int		ft_check_path(t_map *map, char *fn);
int		ft_min_elements(char **array);
// Textures and images
void	ft_get_textures(t_map *map);
void	ft_get_images(t_map *map);
void	ft_delete_textu(t_map *map);
// Render images
void	ft_print_elements(t_map *map, t_image *image);
void	ft_print_floor(t_map *map, t_image *image);
// Movements
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_moves(t_map *map);
//Enemies
void	ft_alien(t_map *map);
// Collectibles check
void	ft_count_collectibles(t_map *map);
int		ft_total_collectibles(t_map *map);
// Endscreen
void	ft_check_ending(t_map *map);
// Free
void	ft_free_array(char **array);

#endif
