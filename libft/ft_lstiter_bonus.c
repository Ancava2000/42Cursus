/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:25:33 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/30 15:42:36 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/*
void print_content(void *content)
{
	printf("Content: %s/n", (char *)content);
}
int main ()
{
	t_list *lst = ft_lstnew("Hello");
	ft_lstadd_back(&lst, ft_lstnew("World"));
	ft_lstiter(lst, print_content);  Returns: it will iterate every node and aplly the function indicated in the second parameter. In this case, it prints "Hello" and "World".
}
*/
