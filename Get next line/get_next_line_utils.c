/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:10:24 by acarro-v          #+#    #+#             */
/*   Updated: 2024/05/28 11:17:28 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	int				len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
		{
			return (NULL);
		}
		ft_strlcpy(new, s1, len + 1);
		ft_strlcat(new, s2, len + 1);
		return (new);
	}
	return (NULL);
}
