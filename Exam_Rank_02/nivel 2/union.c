#include <unistd.h>

int main (int argc, char **argv)
{
    int i;
    int j;
    unsigned char seen[256] = {0};
    
    i = 0;
    j = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (!seen[argv[1][i]])
            {
                seen[argv[1][i]] = 1;
                write (1, &argv[1][i], 1);
            }
            i++;
        }
        while (argv[2][j])
        {
            if (!seen[argv[2][j]])
            {
                seen[argv[2][j]] = 1;
                write (1, &argv[2][j], 1);
            }
            j++;
        }
    }
    write (1, "\n", 1);
    return (0);
}
