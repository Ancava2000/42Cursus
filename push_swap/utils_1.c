/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:46:24 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/16 13:46:02 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function that find the min number in the given stack,
// with the help of a temporal variable
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

// Function that find the max number in the given stack, 
// with the help of a temporal variable
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

// Function that finds the index of a number in the stack 
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

/* Function that returns the index number in stack "b"
that the int pushed_nbr will be get once it's pushed.
This function follows the rule that each "a" node
has a target "b" node, this being the closest smallest number to the "a" node
If there is no closest smallest number, the target node is the maximum number */
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

/* Function that returns the index number in stack "a"
that the int pushed_nbr will be get once it's pushed.
This function follows the rule that each "b" node
has a target "a" node, this being the closest biggest number to the "b" node
If there is no closest biggest number, the target node is the minimum number */
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
