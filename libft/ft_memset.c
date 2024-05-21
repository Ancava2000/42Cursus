/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:36:18 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/19 13:24:50 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (len > i)
	{
		p[i++] = (unsigned char)c;
	}
	return (b);
}
/*
int main()
{
	char buffer[10];
	ft_memset(buffer, 'A', sizeof(buffer));  Returns: AAAAAAAAAA
 	char *str = "This is string.h library function"
  	ft_memset(str, '$', 7);  Returns: $$$$$$$ string.h library function
}
*/
