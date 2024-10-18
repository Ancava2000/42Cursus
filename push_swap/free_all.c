/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:17:34 by acarro-v          #+#    #+#             */
/*   Updated: 2024/08/20 15:31:57 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)-> next;
		(*lst)-> nbr = 0;
		free(*lst);
		*lst = temp;
	}
}

void	ft_freestr(char **lst)
{
	char	*i;

	if (!lst)
		return ;
	while (*lst)
	{
		i = *lst;
		lst++;
		free(i);
	}
	*lst = NULL;
}
