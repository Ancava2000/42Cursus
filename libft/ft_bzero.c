/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:06:34 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/15 17:47:48 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = 0;
		i++;
	}
}

/*
int main()
{
	char buffer[10];
	ft_bzero(buffer, sizeof(buffer));  Devuelve: Todos los bytes de buffer (10) a cero.
 	int numbers[5];
  	ft_bzero(numbers, 5 * sizeof(int);  Devuelve: Todos los bytes de numbers (5) a cero.
}
*/
