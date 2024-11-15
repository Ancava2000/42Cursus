/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:29:40 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 14:11:58 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		slen;
	char		*aux;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (slen > 0 && ft_strchr(set, s1[slen]))
		slen--;
	aux = ft_substr((char *) s1, 0, slen + 1);
	return (aux);
}
