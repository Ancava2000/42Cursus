/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:46:24 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 13:49:47 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *a)
{
	int	i;

	i = a-> nbr;
	while (a)
	{
		if (a-> nbr < i)
			i = a-> nbr;
		a = a-> next;
	}
	return (i);
}

int	ft_max(t_stack *a)
{
	int	i;

	i = a-> nbr;
	while (a)
	{
		if (a-> nbr > i)
			i = a-> nbr;
		a = a-> next;
	}
	return (i);
}

int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = 0;
	while (a-> nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	ft_connection_in_b(t_stack *stack_b, int pushed_nbr)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (pushed_nbr > stack_b->nbr && pushed_nbr < ft_ltlast(stack_b)-> nbr)
		i = 0;
	else if (pushed_nbr < ft_min(stack_b) || pushed_nbr > ft_max(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		temp = stack_b-> next;
		while (pushed_nbr > stack_b->nbr || pushed_nbr < temp->nbr)
		{
			stack_b = stack_b -> next;
			temp = temp -> next;
			i++;
		}
	}
	return (i);
}

int	ft_connection_in_a(t_stack *stack_a, int pushed_nbr)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (pushed_nbr < stack_a->nbr && pushed_nbr > ft_ltlast(stack_a)-> nbr)
		i = 0;
	else if (pushed_nbr < ft_min(stack_a) || pushed_nbr > ft_max(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		temp = stack_a-> next;
		while (pushed_nbr < stack_a->nbr || pushed_nbr > temp->nbr)
		{
			stack_a = stack_a -> next;
			temp = temp -> next;
			i++;
		}
	}
	return (i);
}
