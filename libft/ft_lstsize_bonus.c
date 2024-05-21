/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:52:14 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 10:56:11 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst -> next;
	}
	return (counter);
}

/*
int main ()
{
	t_list *lst = ft_lstnew("Hello");
	ft_lstadd_back(&lst, ft_lstnew("World"));  You create a new element (World), adding it in the end of the existing list (lst).
	ft_lstsize(lst);   Returns: 2, as it is the number of elements in lst.
	return (0);
}
*/
