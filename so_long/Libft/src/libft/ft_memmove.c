/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:15:03 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:24 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	if (!dst && !src)
		return (0);
	if (p_dst > p_src)
	{
		while (len-- > 0)
		{
			p_dst[len] = p_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}
