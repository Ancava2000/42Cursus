/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:38:51 by acarro-v          #+#    #+#             */
/*   Updated: 2025/01/16 13:05:15 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
	    while (argv[1][i])
	    {
		    if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
		        argv[1][i] += 1;
		    else if (argv[1][i] >= 'a' && argv[1][i] <= 'y')
			    argv[1][i] += 1;
		    else if (argv[1][i] == 'Z' || argv[1][i] == 'z')
			    argv[1][i] -= 25;
		    write (1, &argv[1][i], 1);
		    i++;
	    }
	}
	write (1, "\n", 1);
	return (0);
}
