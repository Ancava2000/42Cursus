/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:28:48 by acarro-v          #+#    #+#             */
/*   Updated: 2025/01/16 11:44:11 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void fizzbuzz(int nb)
{
	char	*str;

	str = "0123456789";
	if (nb > 9)
		fizzbuzz (nb / 10);
	write (1, &str[nb % 10], 1);
}

int main ()
{
	int	nb;
	
	nb = 0;
	while (nb <= 100)
	{
		if (nb % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write (1, "fizz", 4);
		else if (nb % 5 == 0)
			write (1, "buzz", 4);
		else
			fizzbuzz(nb);
		write (1, "\n", 1);
		nb++;
	}
	return (0);
}