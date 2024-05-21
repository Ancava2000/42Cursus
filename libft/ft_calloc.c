/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:57:36 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/23 11:35:07 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}

/*
int main ()
{	
	int *numbers = ft_calloc(25, sizeof(int));   Returns: The function allocates memory for an array of 25 integers and initializes the memory to zeros.
 	return (0);
}
*/
