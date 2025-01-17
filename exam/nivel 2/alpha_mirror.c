#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
	    while (argv[1][i])
	    {
		    if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
          argv[1][i] = ('A' + 'Z') - argv[1][i];
		    else if (argv[1][i] >= 'a' && argv[1][i] <= 'y')
			    argv[1][i] = ('a' + 'z') - argv[1][i];
			  write (1, &argv[1][i], 1);
		    i++;
	    }
	}
	write (1, "\n", 1);
	return (0);
}
