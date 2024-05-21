/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:20:24 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 15:52:09 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
void del_content(void *content)
{
    free(content);
}
int main ()
{
	t_list *lst = ft_lstnew("Hello");
	ft_lstadd_back(&lst, ft_lstnew("World"));
	ft_lstclear(&lst, del_content);   Returns: Both elements of the linked list are freed, including their content, and the ‘lst’ pointer is set to NULL, indicating that the list is empty.
 	Return (0);
}
*/
