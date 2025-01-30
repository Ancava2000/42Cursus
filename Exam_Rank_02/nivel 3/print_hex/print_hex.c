#include <unistd.h>

int		ft_atoi(char *s)
{
	unsigned int    result;
	int		sign;

    result = 0;
    sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
	    sign *= -1;
	if (*s == '+' || *s == '-')
	    s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + *s - '0';
		s++;
    }
	return (sign * result);
}

void ft_hex(int n)
{
    char *hex = "0123456789abcdef";
    
    if (n >= 16)
        ft_hex(n / 16);
    n = hex[n % 16];
    write (1, &n, 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_hex(ft_atoi(argv[1]));
    write (1, "\n", 1);
    return (0);
}
