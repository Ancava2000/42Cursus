/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:53:23 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/16 14:53:39 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function applies the ra, rb or rr rotation
operation according to the condition,
until the nodes are in the first position.
It always does the pb or pa operation. */
int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c && ft_connection_in_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)-> nbr != c)
			ft_ra(a, 0);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)-> nbr != c && ft_connection_in_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)-> nbr != c)
			ft_rb(b, 0);
		while (ft_connection_in_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

/* This function applies the rra, rrb or rrr reverse
rotation operation according to the condition,
until the nodes are in the first position.
It always does the pb or pa operation. */
int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c && ft_connection_in_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)-> nbr != c)
			ft_rra(a, 0);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)-> nbr != c && ft_connection_in_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)-> nbr != c)
			ft_rrb(b, 0);
		while (ft_connection_in_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

/* This function applies the rra or rb
rotation operation according to the condition,
until the nodes are in the first position.
It always does the pb or pa operation. */
int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c)
			ft_rra(a, 0);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_connection_in_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->nbr != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

/* This function applies the ra or rrb rotation
operation according to the condition,
until the nodes are in the first position.
It always does the pb or pa operation. */
int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c)
			ft_ra(a, 0);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_connection_in_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)-> nbr != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
