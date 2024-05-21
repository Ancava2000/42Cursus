/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:14:44 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 15:44:37 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (NULL == node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

/*
int main ()
{
	t_list *new_element = ft_lstnew("Hello World!");   Returns: It creates a new node in the list (new_element) with the content "Hello World!".
	return (0);
}
*/
