/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:57:36 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:11 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*s;

	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	i = 0;
	s = (unsigned char *)ptr;
	while (i < (count * size))
	{
		s[i] = (unsigned char) 0;
		i++;
	}
	return ((void *)s);
}
