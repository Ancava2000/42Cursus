/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:14:44 by acarro-v          #+#    #+#             */
/*   Updated: 2024/08/14 15:43:57 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (NULL == node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
