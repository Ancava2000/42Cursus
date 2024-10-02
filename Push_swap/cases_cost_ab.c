/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_cost_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:43:29 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 14:17:44 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_connection_in_b(b, nbr);
	if (i < ft_find_index(a, nbr))
		i = ft_find_index(a, nbr);
	return (i);
}

int	ft_case_rrarrb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_connection_in_b(b, nbr))
		i = ft_sizelist(b) - ft_connection_in_b(b, nbr);
	if (i < (ft_sizelist(a) - ft_find_index(a, nbr)) && ft_find_index(a, nbr))
		i = ft_sizelist(a) - ft_find_index(a, nbr);
	return (i);
}

int	ft_case_rrarb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(a, nbr))
		i = ft_sizelist(a) - ft_find_index(a, nbr);
	i = ft_connection_in_b(b, nbr) + i;
	return (i);
}

int	ft_case_rarrb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_connection_in_b(b, nbr))
		i = ft_sizelist(b) - ft_connection_in_b(b, nbr);
	i = ft_find_index(a, nbr) + i;
	return (i);
}
