/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:20:59 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/21 12:07:46 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* It creates the stack "a" and adds the input nodes(numbers). 
If there's no stack "a" or if there is a number repeated (checkdup),
it frees the stack and shows the error message.  
Finally, if the nodes in stack "a" aren't sort (checksort),
they are sorted by the function and freed.*/
int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = ft_addnodes(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksort(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
