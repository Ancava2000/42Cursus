#include <stdio.h>  // printf
#include <stdlib.h>  // atoi

void ft_prime(int nb)
{
    unsigned i = 2;    //start with 2!!
    
    if (nb == 1)
        printf("1");
    while (i <= nb)
    {
        if (nb % i == 0)
        {
            printf("%d", i);
            if (nb != i)
                printf("*");
            nb = nb / i;
        }
        else
            i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_prime(atoi(argv[1]));
    printf("\n");
    return (0);
}

/*
12
12 % 2 == 0      2 *
6 % 2 == 0       2 * 2
3 % 2 != 0 
3 % 3 == 0       2 * 2 * 3
*/
