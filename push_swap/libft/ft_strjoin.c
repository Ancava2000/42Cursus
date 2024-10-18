/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:48:37 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/16 12:04:47 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;

	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s || !s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s[ft_strlen(s1) + i] = s2[i];
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
