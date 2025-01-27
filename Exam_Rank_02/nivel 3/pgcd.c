#include <stdlib.h>
#include <stdio.h>

int ft_pgcd(int s1, int s2)
{
    if (s1 > 0 && s2 > 0)
    {
        while (s1 != s2)
        {
            if (s1 > s2)
                s1 = s1 - s2;
            else
                s2 = s2 - s1;
        }
        printf("%d", s1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_pgcd(atoi(argv[1]), atoi(argv[2]));
    printf ("\n");
    return (0);
}
