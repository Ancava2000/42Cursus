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
