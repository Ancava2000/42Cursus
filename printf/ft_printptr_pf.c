/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:40:41 by acarro-v          #+#    #+#             */
/*   Updated: 2024/05/07 15:08:01 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_pf(unsigned long long ptr)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_putptr_pf(ptr / 16);
	ft_putchar_pf(symbols[ptr % 16]);
	count++;
	return (count);
}

int	ft_printptr_pf(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr_pf("0x");
	count += ft_putptr_pf(ptr);
	return (count);
}
