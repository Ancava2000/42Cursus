/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:18 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/22 15:42:45 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*aux;

	aux = NULL;
	while (*s)
	{
		if (*s == (char)c)
			aux = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)aux);
}
