/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:10:24 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 14:18:10 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line/get_next_line.h"

void	ft_get_bzero(void *s, size_t n)
{
	char			*b;
	size_t			i;

	b = (char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = 0;
		i++;
	}
}

void	*ft_get_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}

size_t	ft_get_strlen(char *s)
{
	unsigned long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_get_strchr(char *s, int c)
{
	unsigned long int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (s);
	return (NULL);
}

char	*ft_get_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;

	s = malloc((ft_get_strlen(s1) + ft_get_strlen(s2) + 1) * sizeof(char));
	if (!s || !s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s[ft_get_strlen(s1) + i] = s2[i];
	s[ft_get_strlen(s1) + i] = '\0';
	return (s);
}
