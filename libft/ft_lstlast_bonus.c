/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:56:43 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 15:45:18 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

/*
int main ()
{
	t_list *lst = ft_lstnew("Hello");   Create a new node (lst) with the content "Hello".
	ft_lstadd_back(&lst, ft_lstnew("World"));  It adds the content "World" at the end of the existing list (lst).
	t_list *last_elem = ft_lstlast(lst);    Return: The node *lst_elem points to the content "World".
 	return (0);
}
*/
