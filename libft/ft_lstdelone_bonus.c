/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:12:02 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 15:42:00 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst -> content);
	free (lst);
}

/*
void del_content(void *content)
    free(content);
int main ()
{
	t_list *lst = ft_lstnew("Hello");   Creates a new node (lst) with the content "Hello".
	ft_lstdelone(lst, del_content);    Returns: It frees the content "Hello", the node *lst, and it sets the node to NULL.
	return (0);
}
*/
