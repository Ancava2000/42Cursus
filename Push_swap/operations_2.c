/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:07:44 by acarro-v          #+#    #+#             */
/*   Updated: 2024/09/20 13:07:02 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*aux;

	if (a || (*a)->next)
	{
		aux = *a;
		*a = ft_ltlast(*a);
		(*a)->next = aux;
		*a = aux->next;
		aux->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack **b)
{
	t_stack	*aux;

	if (b || (*b)->next)
	{
		aux = *b;
		*b = ft_ltlast(*b);
		(*b)->next = aux;
		*b = aux->next;
		aux->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (a || ((*a)->next) || b || ((*b)->next))
	{
		aux = *a;
		*a = ft_ltlast(*a);
		(*a)->next = aux;
		*a = aux->next;
		aux->next = NULL;
		aux = *b;
		*b = ft_ltlast(*b);
		(*b)->next = aux;
		*b = aux->next;
		aux->next = NULL;
		write(1, "rr\n", 3);
	}
}
