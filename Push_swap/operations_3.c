/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:21:07 by acarro-v          #+#    #+#             */
/*   Updated: 2024/08/26 12:49:39 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*aux;
	int		i;

	if (*a || (*a)-> next)
	{
		aux = *a;
		i = 0;
		while ((*a)->next)
		{
			i++;
			*a = (*a)->next;
		}
		(*a)-> next = aux;
		while (i > 1)
		{
			aux = aux->next;
			i--;
		}
		aux->next = NULL;
		write (1, "rra\n", 4);
	}
}

void	ft_rrb(t_stack **b)
{
	t_stack	*aux;
	int		i;

	if (*b || (*b)-> next)
	{
		aux = *b;
		i = 0;
		while ((*b)->next)
		{
			i++;
			*b = (*b)->next;
		}
		(*b)-> next = aux;
		while (i > 1)
		{
			aux = aux->next;
			i--;
		}
		aux->next = NULL;
		write (1, "rrb\n", 4);
	}
}

void	ft_rrr_2(t_stack **b)
{
	t_stack	*aux;
	int		i;

	if (*b || (*b)-> next)
	{
		aux = *b;
		i = 0;
		while ((*b)->next)
		{
			i++;
			*b = (*b)->next;
		}
		(*b)-> next = aux;
		while (i > 1)
		{
			aux = aux->next;
			i--;
		}
		aux->next = NULL;
		write (1, "rrr\n", 4);
	}
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		i;

	if (*a || (*a)-> next)
	{
		aux = *a;
		i = 0;
		while ((*a)->next)
		{
			i++;
			*a = (*a)->next;
		}
		(*a)-> next = aux;
		while (i > 1)
		{
			aux = aux->next;
			i--;
		}
		aux->next = NULL;
		ft_rrr_2(b);
	}
}
