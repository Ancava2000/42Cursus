/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:26:11 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 14:18:18 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> /*Memory*/
# include <unistd.h> /*File descriptor functions*/
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

/* auxiliary functions*/
void	ft_get_bzero(void *s, size_t n);
void	*ft_get_calloc(size_t count, size_t size);
size_t	ft_get_strlen(char *s);
char	*ft_get_strchr(char *s, int c);
char	*ft_get_strjoin(char *s1, char *s2);

#endif