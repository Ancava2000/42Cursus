#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int len;
	int temp;
	int is_negative = 0;

	if (nbr == -2147483648)
		return ("-2147483648");
    	if (nbr < 0)
    	{
        	is_negative = 1;
        	nbr = -nbr;
    	}
    	temp = nbr;
	len = 0;
    	while (temp != 0)
    	{
        	temp /= 10;
        	len++;
    	}
    	len += is_negative;
    	char *str = (char *)malloc(len + 1);
    	if (!str)
        	return (NULL);
    	str[len] = '\0';
    	if (nbr == 0)
    	{
        	str[0] = '0';
        	return (str);
    	}
	len -= 1;
    	while (nbr > 0)
	{
        	str[len] = (nbr % 10) + '0';
        	nbr /= 10;
		len--;
    	}
    	if (is_negative)
        	str[0] = '-';
    	return (str);
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
