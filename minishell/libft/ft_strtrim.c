/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:29:40 by acarro-v          #+#    #+#             */
/*   Updated: 2025/07/21 13:36:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*new;
	unsigned int	start;
	unsigned int	end;

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
