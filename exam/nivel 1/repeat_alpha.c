/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:54:27 by acarro-v          #+#    #+#             */
/*   Updated: 2025/01/16 12:13:23 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	int	count;
	
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			count = 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				count = (argv[1][i] - 'a') + 1;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				count = (argv[1][i] - 'A') + 1;
			while (count--)
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
