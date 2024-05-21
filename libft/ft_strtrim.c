/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:29:40 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/24 12:21:38 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
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

/*
int main ()
{
	char str[] = "ssssHello, World!ssss";
	char set[] = "s";
	ft_strtrim(str, set);   Returns: A new string without the char set ("s") found at the beginning and the end of the input string ("Hello, World).
	return (0);
}
*/
