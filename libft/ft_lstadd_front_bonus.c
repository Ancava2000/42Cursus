/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:10:05 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 10:22:42 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

/*
int main ()
{
	t_list *lst = ft_lstnew("Hello");
	t_list *new = ft_lstnew("World");
	ft_lstadd_front(&lst, new);   Returns: The element new is added at the beginning of the existing list.
 	return (0);
}
*/
