/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:53:23 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 13:47:00 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c && ft_connection_in_b(*b, c) > 0)
			ft_rr(a, b);
		while ((*a)-> nbr != c)
			ft_ra(a);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)-> nbr != c && ft_connection_in_a(*a, c) > 0)
			ft_rr(a, b);
		while ((*b)-> nbr != c)
			ft_rb(b);
		while (ft_connection_in_a(*a, c) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c && ft_connection_in_b(*b, c) > 0)
			ft_rrr(a, b);
		while ((*a)-> nbr != c)
			ft_rra(a);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)-> nbr != c && ft_connection_in_a(*a, c) > 0)
			ft_rrr(a, b);
		while ((*b)-> nbr != c)
			ft_rrb(b);
		while (ft_connection_in_a(*a, c) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c)
			ft_rra(a);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_connection_in_a(*a, c) > 0)
			ft_rra(a);
		while ((*b)->nbr != c)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char n)
{
	if (n == 'a')
	{
		while ((*a)-> nbr != c)
			ft_ra(a);
		while (ft_connection_in_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_connection_in_a(*a, c) > 0)
			ft_ra(a);
		while ((*b)-> nbr != c)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}
