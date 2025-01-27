#include <stdlib.h>
#include <stdio.h>

int ft_pgcd(int s1, int s2)
{
    unsigned int i;

    i = s1;
    while (s1 > 0)
    {
        if (s1 % i == 0 && s2 % i == 0)
            return (i);
        i--;
    }
    return (1);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        printf ("%d", ft_pgcd(atoi(argv[1]), atoi(argv[2]));
    printf ("\n");
    return (0);
}
