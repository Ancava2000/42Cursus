#include <unistd.h>

int	ft_atoi(char *s)
{
	int	res = 0;

	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		s++;
	}
	return (res);
}

void	putstr(int nb)
{
	char	str;

	if (nb >= 10)
		putstr(nb / 10);
	str = nb % 10 + '0';
	write(1, &str, 1);
}

int	isprime(int nb)
{
	int	i = 2;  // start with 2!!

	if (nb <= 1)
		return (0);
	while (i * i <= nb)   // remember the =
	{
		if (nb % i == 0)
			return (0);
		i++;            // add until nb % i == 0 or nb is prime
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	sum;
	int	nb;

	if (argc == 2)
	{
		sum = 0;
		nb = ft_atoi(argv[1]);   //1. convert str to int
		while (nb > 0)
		{
			if (isprime(nb))
				sum += nb;   //2. add prime nb to sum
			nb--;
		}
		putstr(sum);  //3. convert int to char to write
	}
	if (argc != 2)
		putstr(0);
	write (1, "\n", 1);
	return (0);
}
