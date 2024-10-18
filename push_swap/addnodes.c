/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addnodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:55:29 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/09 13:38:21 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function that converts the input string to numbers.
int	atoi2(const char *str)
{
	long long int	i;
	int				neg;

	i = 0;
	neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((neg * i) > 2147483648 || (neg * i) < -2147483648)
		ft_error();
	return (neg * i);
}

/* Function that splits the string according to the spaces, 
tranforms them to numbers and adds them to the stack.
Lastly, it frees the string stored in the temp variable */
t_stack	*ft_subprocess(char **argv)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	temp = ft_split(argv[1], 32);
	while (temp[i])
	{
		j = atoi2(temp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(temp);
	free(temp);
	return (a);
}

/* It creates an empty stack "a" and checks the number of argc.
If there are less than 2 (meaning that the only input is the program's name),
it exits the program. If there are two, 
it means that the input numbers are a string,
so it enters the subprocess function to split and convert them to numbers. 
Lastly, it there are more argc, in a loop, 
it converts the input to numbers and adds
each one to the stack "a".*/
t_stack	*ft_addnodes(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	if (argc < 2)
		exit(0);
	if (argc == 2)
		a = ft_subprocess(argv);
	else
	{
		while (i < argc)
		{
			j = atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
