/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_cost_ba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:43:29 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 12:22:59 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// From stack "b" to stack "a"
// This function calculates the number of moves needed to put the nodes in first position. ra + rb case 
int	ft_case_rarb_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_connection_in_a(a, nbr);
	if (i < ft_find_index(b, nbr))
		i = ft_find_index(b, nbr);
	return (i);
}

// This function calculates the number of moves needed to put the nodes in first position. rra + rrb case 
int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_connection_in_a(a, nbr))
		i = ft_sizelist(a) - ft_connection_in_a(a, nbr);
	if ((i < (ft_sizelist(b) - ft_find_index(b, nbr))) && ft_find_index(b, nbr))
		i = ft_sizelist(b) - ft_find_index(b, nbr);
	return (i);
}

// This function calculates the number of moves needed to put the nodes in first position. rra + rb case 
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_connection_in_a(a, nbr))
		i = ft_sizelist(a) - ft_connection_in_a(a, nbr);
	i = ft_find_index(b, nbr) + i;
	return (i);
}

// This function calculates the number of moves needed to put the nodes in first position. ra + rrb case 
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(b, nbr))
		i = ft_sizelist(b) - ft_find_index(b, nbr);
	i = ft_connection_in_a(a, nbr) + i;
	return (i);
}
