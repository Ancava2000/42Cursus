/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:59:44 by acarro-v          #+#    #+#             */
/*   Updated: 2024/08/26 12:41:39 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*aux;

	if (*a || (*a)-> next)
	{
		aux = *a;
		*a = (*a)-> next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stack **b)
{
	t_stack	*aux;

	if (*b || (*b)-> next)
	{
		aux = *b;
		*b = (*b)-> next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (*a || ((*a)-> next) || *b || ((*b)-> next))
	{
		aux = *a;
		*a = (*a)-> next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		aux = *b;
		*b = (*b)->next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "ss\n", 3);
	}
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (*b)
	{
		aux = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = aux;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (*a)
	{
		aux = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = aux;
		write(1, "pb\n", 3);
	}
}

