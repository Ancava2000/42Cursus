#include <unistd.h>

void ft_cap(char *s1)
{
    int i;
    
    i = 0;
    if (s1[i] >= 'a' && s1[i] <= 'z')
        s1[i] -= 32;
    write (1, &s1[i], 1);
    while(s1[++i])
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] += 32;
        if ((s1[i] >= 'a' && s1[i] <= 'z') && (s1[i - 1] == ' ' || s1[i - 1] == '\t'))
            s1[i] -= 32;
        write (1, &s1[i], 1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        int i = 1;
        while(i < argc)
        {
            ft_cap(argv[i]);
            write (1, "\n", 1);
            i++;
        }
    }
}
