/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:20:24 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:18 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = current -> next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
