/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:39:41 by acarro-v          #+#    #+#             */
/*   Updated: 2024/05/07 11:30:39 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdigit_pf(long int num, int base, char c)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (c == 'X')
		symbols = "0123456789ABCDEF";
	if (num < 0)
	{
		write(1, "-", 1);
		return (ft_putdigit_pf(-num, base, c) + 1);
	}
	else if (num < base)
		return (ft_putchar_pf(symbols[num]));
	else
	{
		count += ft_putdigit_pf(num / base, base, c);
		return (count + ft_putdigit_pf(num % base, base, c));
	}
}
