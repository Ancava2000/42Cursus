/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:29:40 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/16 12:09:28 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	char			*new;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	i = 0;
	start = 0;
	end = 0;
	if (*s1)
	{
		while (ft_strchr(set, s1[start]))
			start++;
		end = ft_strlen(s1);
		while (ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		new = ft_substr(s1, start, end - start);
		if (!new)
			return (NULL);
		return (new);
	}
	else
	{
		new = ft_substr(s1, 0, 0);
		return (new);
	}
}
