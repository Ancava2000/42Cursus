#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void rev_wstr(char *str)
{
    int i;
    int j;
    int word;
    
    i = 0;
    word = 1;
    while(str[i] != '\0')
        i++;
    while(i >= 0)
    {
        j = 0;
        while(i >= 0 && (str[i] == '\0' || is_space(str[i])))
            i--;
        j = i;
        while(j >= 0 && !is_space(str[j]))
            j--;
        if (!word)
            write (1, " ", 1);
        write (1, str + j + 1, i - j);
        word = 0;
        i = j;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}
