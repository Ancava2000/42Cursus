#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	flag;

	if (argc == 2)
	{
		i = 0;
		flag = 0;
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == 32 || argv[1][i] == 9)
				flag = 1;
			if (argv[1][i] != 32 || argv[1][i] != 9)
			{
				if (flag)
					write (1, " ", 1);
				flag = 0;
				write (1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
