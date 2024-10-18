/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:17:39 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/16 12:43:36 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

/*This function checks if there are any duplicated number. 
The temp variable stores the next number in the list,
comparing the first number (stored in "a"),
with all the numbers (temp) of the list.
Next, the "a" stores the next number and the process 
is repeated until there are no numbers to check.
If the "a" and temp variables match, returns 1.*/
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

/* Function that checks if the initial input numbers
are ordered from smallest to largest */
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
