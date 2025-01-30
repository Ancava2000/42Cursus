#include <stdlib.h>

int ft_length(int n)
{
    int length = 0;
    if (n == 0)
        return 1;  // "0" has a length of 1
    if (n < 0)
        length = 1;  // For negative numbers, add space for the '-'
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return (length);
}

void ft_convert(int n, char *string, int length)
{
    while (length > 0)
    {
        string[length - 1] = n % 10 + '0';  // Store digit as char
        n /= 10;
        length--;
    }
}

char *ft_itoa(int nbr)
{
    int sign;
    int length;
    long n;
    char *string;

    if (nbr == -2147483648)
        return "-2147483648";
    sign = 0;
    n = nbr;
    if (nbr < 0)
    {
        sign = 1;  // Flag for negative number
        n = -nbr;  // Work with the positive equivalent
    }
    length = ft_length(n);
    string = (char *)malloc(sizeof(char) * (length + 1));
    if (!string)
        return NULL;
    string[length] = '\0';  // Null-terminate the string
    ft_convert(n, string, length);
    if (sign)
        string[0] = '-';  // Add negative sign if necessary
    return string;
}
