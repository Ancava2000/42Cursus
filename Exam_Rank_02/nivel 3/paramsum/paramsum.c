#include <unistd.h>

void paramsum(int nb)
{
    char s;
    if (nb > 9)
        paramsum(nb / 10);
    s = (nb % 10) + '0';
    write(1, &s, 1);
}

int main(int argc, char **argv)
{
    if (argc == 0)
        write (1, "0", 1);
    else
        paramsum(argc - 1);
    write (1, "\n", 1);
}
