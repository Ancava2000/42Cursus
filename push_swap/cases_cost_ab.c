/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_cost_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:43:29 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/09 11:46:01 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function calculates the number of moves needed
to put the nodes in first position. 
First, the i variable stores the index the node "a" will get
in the stack "b", once it's pushed.
Second, if that value is less than the actual index of node "a"
in the stack "a", the variable would
store that new value. Basically, this function returns
the biggest number depending of both indexes */
int	ft_case_rarb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_connection_in_b(b, nbr);
	if (i < ft_find_index(a, nbr))
		i = ft_find_index(a, nbr);
	return (i);
}

/* This function calculates the number of moves needed
to put the nodes in first position. 
First, the i variable stores the reverse index the node "a" will get
in the stack "b", once it's pushed.
Second, if that value is less than the actual reverse index
of node "a" in the stack "a", the variable would
store that new value. Basically, this function returns
the biggest number depending of both indexes */
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

/* This function calculates the number of moves needed
to put the nodes in first position. 
First, the i variable stores the actual reverse index of the node "a".
Second, the i variable stores the sum of the index the node "a"
will get in the stack "b" plus the reverse index. 
Basically, this function returns
the biggest number depending of both indexes.
In this case, we do the sum because this case
can't make both moves at the same time */
int	ft_case_rrarb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(a, nbr))
		i = ft_sizelist(a) - ft_find_index(a, nbr);
	i = ft_connection_in_b(b, nbr) + i;
	return (i);
}

/* This function calculates the number of moves
needed to put the nodes in first position. 
First, the i variable stores the reverse index
the node "a" will get in the stack "b"
Second, the i variable stores the sum of the actual index
of the node "a" plus the reverse index. 
Basically, this function returns 
the biggest number depending of both indexes.
In this case, we do the sum because
this case can't make both moves at the same time */
int	ft_case_rarrb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_connection_in_b(b, nbr))
		i = ft_sizelist(b) - ft_connection_in_b(b, nbr);
	i = ft_find_index(a, nbr) + i;
	return (i);
}
