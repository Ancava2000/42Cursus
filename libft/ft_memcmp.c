/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:16:53 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/12 14:00:57 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
		{
			return (p_s1[i] - p_s2[i]);
		}
		i++;
	}
	return (0);
}

/*
int main ()
{
	char *s1 = "Holb";
	char *s2 = "Hola";
	ft_memcmp(arr1, arr2, 5);   Returns: 1, the ascii difference between b vs a.
	int a = 123;
	int b = 123;
	ft_memcmp(a, b, 3);   Returns: 0, because they are both the same int.
	return (0);
}
*/
