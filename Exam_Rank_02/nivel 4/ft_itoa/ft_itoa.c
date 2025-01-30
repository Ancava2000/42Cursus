#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i;
}

char	*ft_strrev(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(str);
	while (j > i)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	int i;
	int neg;
	char *str;

	i = 0;
	neg = 0;
	str = malloc(sizeof(char) * 12);  // *12; 10: The maximum number of digits for a 32-bit signed integer + 1 (NULL) + 1 (negative '-')
	if (str == NULL || nbr == 0)
	{
		if (nbr == 0)
		    return ("0");   // for the case of 0
		else
		    return (NULL);
	}
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;  // to make it positive
	}
	while (nbr)
	{
		str[i++] = (nbr % 10) + '0';  // to convert to str
		nbr /= 10;
	}
	if (neg)
		str[i] = '-';  // writes the sign at the end
	return (ft_strrev(str)); // the digits are stores in reverse order. (-1234 -> 4321-)
}

/*
#include <stdio.h>

int main()
{
	printf("0 || %s\n", ft_itoa(0));
	printf("35 || %s\n", ft_itoa(35));
	printf("3587 || %s\n", ft_itoa(3587));
	printf("0 || %s\n", ft_itoa(-0));
	printf("-320 || %s\n", ft_itoa(-320));
	printf("-2147483648 || %s\n", ft_itoa(-2147483648));
	printf("2147483647 || %s\n", ft_itoa(2147483647));
}
*/
