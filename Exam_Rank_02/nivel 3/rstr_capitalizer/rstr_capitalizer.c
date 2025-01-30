#include <unistd.h>

int capitalizer(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] == 32 || s[i + 1] == 9 || s[i + 1] == '\0')
            s[i] -= 32;
        write(1, &s[i++], 1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write (1, "\n", 1);
    else
    {
        int i = 1;
        while (i < argc)
        {
            function(argv[i]);
            write (1, "\n", 1);
            i++;
        }
    }
    return (0);
}
