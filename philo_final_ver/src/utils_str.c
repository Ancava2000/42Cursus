#include "../include/philo.h"

// Write the message indicated and the standard error (2). The message is shown in the console.
void	ft_error(char *message, int fd)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write(fd, &message[i], 1);
		i++;
	}
}

int	atoi_int(const char *str)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0' && str[i] != ' ')
		return (-1);
	if (res > INT_MAX)
		return (-1);
	return (res);
}

int	atoi_ll(const char *str)
{
	unsigned int	i;
	long long		res;

	i = 0;
	res = 0;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0' && str[i] != ' ')
		return (-1);
	if (res > LLONG_MAX)
		return (-1);
	return (res);
}
