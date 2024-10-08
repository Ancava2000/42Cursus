/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:23:15 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 14:11:26 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* This function sorts and pushes nodes to stack "b" until there are only three nodes in stack "a". 
First it finds the rotate case with the less moves. 
Then it applies the correct case and exits the second loop (the apply case function returns -1) */
void	ft_sort_b_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (ft_sizelist(*stack_a) > 3 && !ft_checksort(*stack_a))
	{
		i = 0;
		temp = *stack_a;
		i = ft_find_rotate_case_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_b(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp -> nbr, 'a');
			else if (i == ft_case_rrarrb_b(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp -> nbr, 'a');
			else if (i == ft_case_rrarb_b(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp -> nbr, 'a');
			else if (i == ft_case_rarrb_b(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp -> nbr, 'a');
			else
				temp = temp -> next;
		}
	}
}

/* This function push nodes from "a" to "b" until there are three nodes in "a". 
In each push, it makes sure that stack "a" is not sorted. 
When three nodes are left in stack "a" and they're not sorted, 
it calls the ft_sort_b_until_three function. Returns the sorted stack "b" */
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_sizelist(*stack_a) > 3 && !ft_checksort(*stack_a))
		ft_pb(stack_a, &stack_b);
	if (ft_sizelist(*stack_a) > 3 && !ft_checksort(*stack_a))
		ft_pb(stack_a, &stack_b);
	if (ft_sizelist(*stack_a) > 3 && !ft_checksort(*stack_a))
		ft_sort_b_until_three(stack_a, &stack_b);
	if (!ft_checksort(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

/* This function sorts and pushes nodes to stack "a" until stack "b" is empty. 
First it finds the rotate case with the less moves. 
Then it applies the correct case and exits the second loop (the apply case function returns -1) 
Finally, it returns the stack "a" */
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_find_rotate_case_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp -> nbr, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp -> nbr, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp -> nbr, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, temp -> nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp -> nbr, 'b');
			else
				temp = temp -> next;
		}
	}
	return (stack_a);
}

/* This function sorts the stack "a" if there are more than two nodes.
First, it pushes from stack "a" to "b" while sorting "b".
Second, it pushes back to stack "a" while sorting it.
Finally, the variable i stores the index of the minimum number in stack "a",
and checks if the index of the min is above of below the list's median.
If is above, it does ra. If is below, it does rra */
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_sizelist(*stack_a) == 2)
		ft_sa(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = (ft_find_index(*stack_a, ft_min(*stack_a)));
		if (i < ft_sizelist(*stack_a) - i)
		{
			while ((*stack_a)-> nbr != ft_min(*stack_a))
				ft_ra(stack_a);
		}
		else
		{
			while ((*stack_a)-> nbr != ft_min(*stack_a))
				ft_rra(stack_a);
		}
	}
}
