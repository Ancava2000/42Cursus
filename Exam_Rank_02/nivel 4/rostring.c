#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    else
        return (0);
}

void first_word(char *str, int j)
{
    while(str[j] != '\0' && !is_space(str[j]))
    {
        write (1, &str[j], 1);
        j++;
    }
}

void rostring(char *str)
{
    int i;
    int j;
    
    j = 0;
    while (str[j] != '\0' && is_space(str[j]))
        j++;
    i = j;
    while (str[i] != '\0' && !is_space(str[i]))
        i++;
    while(str[i] != '\0')
    {
        if (str[i] != '\0' && !is_space(str[i]) && is_space(str[i - 1]))
        {
            while (str[i] != '\0' && !is_space(str[i]))
            {
                write (1, &str[i], 1);
                i++;
            }
            write (1, " ", 1);
        }
        i++;
    }
    first_word(str, j);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        rostring(argv[1]);
    write (1, "\n", 1);
    return (0);
}
