/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:49:20 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/21 12:04:23 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_error_check(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	ft_check_2(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_2(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else
		ft_error_check();
	return (get_next_line(0));
}

void	ft_read_line(t_stack **a, t_stack **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = ft_check(a, b, line);
		free(temp);
	}
	if (*b)
		write(1, "KO\n", 3);
	if (!ft_checksort(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = ft_addnodes(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error_check();
	}
	line = get_next_line(0);
	if (!line && !ft_checksort(a))
		write(1, "KO\n", 3);
	else if (!line && ft_checksort(a))
		write(1, "OK\n", 3);
	else
		ft_read_line(&a, &b, line);
	ft_free(&a);
	ft_free(&b);
	return (0);
}
