#include <unistd.h>

int main (int argc, char **argv)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    if (argc == 3)
    {
        while (argv[2][i])
        {
            if (argv[1][i] == argv[2][j])
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
        {
            i = 0;
            while (argv[1][i])
            {
                write (1, &argv[1][i], 1);
                i++;
            }
        }
    }
    write (1, "\n", 1);
    return (0);
}
