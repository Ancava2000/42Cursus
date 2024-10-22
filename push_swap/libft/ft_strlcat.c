/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:16:58 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/16 12:07:48 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	r_d;
	unsigned int	r_s;

	i = ft_strlen(dst);
	j = 0;
	r_d = ft_strlen(dst);
	r_s = ft_strlen(src);
	if (dstsize < 1)
	{
		return (r_s + dstsize);
	}
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (dstsize < r_d)
		return (r_s + dstsize);
	else
		return (r_d + r_s);
}
