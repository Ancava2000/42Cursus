#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while(str[count] != '\0')
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

int ft_putnbr(long int nb, int base)
{
	char *str = "0123456789abcdef";
	int count = 0;

	if (nb / base > 0)
		count += ft_putnbr(nb / base, base);
	count += ft_putchar(str[nb % base]);
	return (count);
}

int ft_print_d (int nb)
{
	int count = 0;

	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		nb = -nb;
	}
	count += ft_putnbr(nb, 10);
	return (count);
}

int ft_printf(char *str, ...)
{
	va_list av;
	int i;
	int count;

	count = 0;
	i = 0;
	va_start(av, str);
	if (str == NULL)
		return (0);
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i ] == 'd')
				count += ft_print_d(va_arg(av, int));
			else if (str[i] == 's')
				count += ft_putstr(va_arg(av, char *));
			else if (str[i] == 'x')
				count += ft_putnbr(va_arg(av, long int), 16);
			else
				count += write (1, &str[i], 1);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(av);
	return(count);
}
