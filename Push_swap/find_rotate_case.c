/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:28:08 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 14:18:55 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function finds the adecuate rotation combination with the less number of moves.
Within a loop, it compares the variable i (with the number of moves of case rrarrb_b),
with each case. If the original number is bigger, the variable stores the number of moves of the new case,
until it gets the smallest number. In the last step the temp variable starts the loop with the next node.
In each case, after the rotations it always pushes the node. In this case, it pushes the node from
stack "a" to stack "b" */
int	ft_find_rotate_case_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = ft_case_rrarrb_b(a, b, a -> nbr);
	while (temp)
	{
		if (i > ft_case_rarb_b(a, b, temp -> nbr))
			i = ft_case_rarb_b(a, b, temp -> nbr);
		if (i > ft_case_rrarrb_b(a, b, temp -> nbr))
			i = ft_case_rrarrb_b(a, b, temp -> nbr);
		if (i > ft_case_rrarb_b(a, b, temp -> nbr))
			i = ft_case_rrarb_b(a, b, temp -> nbr);
		if (i > ft_case_rarrb_b(a, b, temp -> nbr))
			i = ft_case_rarrb_b(a, b, temp -> nbr);
		temp = temp -> next;
	}
	return (i);
}

/* This function finds the adecuate rotation combination with the less number of moves.
Within a loop, it compares the variable i (with the number of moves of case rrarrb_b),
with each case. If the original number is bigger, the variable stores the number of moves of the new case,
until it gets the smallest number. In the last step the temp variable starts the loop with the next node.
In each case, after the rotations it always pushes the node. In this case, it pushes the node from
stack "b" to stack "a" */
int	ft_find_rotate_case_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = ft_case_rrarrb_a(a, b, b -> nbr);
	while (temp)
	{
		if (i > ft_case_rarb_a(a, b, temp -> nbr))
			i = ft_case_rarb_a(a, b, temp -> nbr);
		if (i > ft_case_rrarrb_a(a, b, temp -> nbr))
			i = ft_case_rrarrb_a(a, b, temp -> nbr);
		if (i > ft_case_rrarb_a(a, b, temp -> nbr))
			i = ft_case_rrarb_a(a, b, temp -> nbr);
		if (i > ft_case_rarrb_a(a, b, temp -> nbr))
			i = ft_case_rarrb_a(a, b, temp -> nbr);
		temp = temp -> next;
	}
	return (i);
}
