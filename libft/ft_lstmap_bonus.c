/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:39:45 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 15:44:12 by acarro-v         ###   ########.fr       */
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

/*
void *uppercase(void *content)
{
	if (content == NULL) 
	{
		return (NULL);
    	}
    	size_t i = 0;
    	char *str = (char *)content;
    	char *result = ft_strdup(str); 
    	while (content)
    	{
     		result[i] = ft_toupper(result[i]);
		i++,    
   	}
    	return result;
}

void free_content(void *content)
{
	free(content);
}
int main ()
{
	t_list *lst = ft_lstnew("hello");
	ft_lstadd_back(&lst, ft_lstnew("world"));
	t_list *new_lst = ft_lstmap(lst, uppercase, free_content);   Returns: A new list with the each content transform by the functions indicated ("HELLO" "WORLD").
 	return (0);
}
*/
