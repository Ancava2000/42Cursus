/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:36 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/06 12:39:14 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 50
# define WND_NAME "so_long"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

//estructura imágenes
typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*character;
	void	*open_exit;
	void	*close_exit;
	void	*enemy;
	void	*player;
}	t_img;

//estrcuctura datos del mapa
typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			moves;
	int			x;
	int			y;
	int			e;
	int			c;
	int			p;
	int			exit;
	int			c_check;
	int			e_check;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;
}	t_map;

#endif