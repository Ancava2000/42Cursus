/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:39:45 by acarro-v          #+#    #+#             */
/*   Updated: 2024/05/29 11:01:16 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (f)
			new_node = ft_lstnew(f(lst -> content));
		else
			new_node = ft_lstnew(lst -> content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back (&new_list, new_node);
		lst = lst -> next;
	}
	return (new_list);
}
