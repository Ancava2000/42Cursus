/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:47:18 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 13:53:28 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

int	ft_format(char sign, va_list ap)
{
	int	count;

	count = 0;
	if (sign == 'c')
		count += ft_putchar_pf(va_arg(ap, int));
	else if (sign == 's')
		count += ft_putstr_pf(va_arg(ap, char *));
	else if (sign == 'p')
		count += ft_printptr_pf(va_arg(ap, unsigned long long));
	else if (sign == 'd')
		count += ft_putdigit_pf((long)va_arg(ap, int), 10, sign);
	else if (sign == 'i')
		count += ft_putdigit_pf((long)va_arg(ap, int), 10, sign);
	else if (sign == 'u')
		count += ft_putdigit_pf((long)va_arg(ap, unsigned int), 10, sign);
	else if (sign == 'x')
		count += ft_putdigit_pf((long)va_arg(ap, unsigned int), 16, sign);
	else if (sign == 'X')
		count += ft_putdigit_pf((long)va_arg(ap, unsigned int), 16, sign);
	else
		count += write(1, &sign, 1);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_format(*str, ap);
		}
		else
			count += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (count);
}
