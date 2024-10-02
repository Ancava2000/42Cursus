/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:17:39 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/02 12:27:16 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_checkdup(t_stack	*a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a -> next;
		while (temp)
		{
			if (a -> nbr == temp -> nbr)
				return (1);
			temp = temp -> next;
		}
		a = a -> next;
	}
	return (0);
}

int	ft_checksort(t_stack	*stack_a)
{
	int	t;

	t = stack_a -> nbr;
	while (stack_a)
	{
		if (t > stack_a -> nbr)
			return (0);
		t = stack_a -> nbr;
		stack_a = stack_a -> next;
	}
	return (1);
}
