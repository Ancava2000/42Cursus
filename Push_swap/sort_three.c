/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:23:47 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 12:45:58 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function sorts the stack "a" if there are three numbers.
First = 1 3 2 -> 2 1 3 -> 1 2 3
Second = 3 2 1 -> 2 1 3 -> 1 2 3
Third = 2 3 1 -> 1 2 3
      = 2 1 3 -> 1 2 3
*/
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)-> nbr)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if (ft_max(*stack_a) == (*stack_a)-> nbr)
	{
		ft_ra(stack_a);
		if (!ft_checksort(*stack_a))
			ft_sa(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_rra(stack_a);
		else
			ft_sa(stack_a);
	}
}
