#include <unistd.h>

int ft_atoi(char *s)
{
    int i;
    
    i = 0;
    while (*s >= '0' && *s <= '9')
        i = i * 10 + *s++ - '0';
    return (i);
}

void putstr(int i)
{
    if (i > 9)
        putstr(i / 10);
    i = (i % 10) + '0';
    write (1, &i, 1);
}

void ft_mult(int n)
{
    int i;
    
    i = 1;
    while (i < 10)
    {
        putstr(i);
        write(1, " x ", 3);
        putstr(n);
        write(1, " = ", 3);
        putstr(i * n);
        write (1, "\n", 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_mult(ft_atoi(argv[1]));
    else
        write (1, "\n", 1);
    return (0);
}
