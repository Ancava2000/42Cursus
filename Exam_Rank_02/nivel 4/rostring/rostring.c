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
    while(str[j] != '\0' && !is_space(str[j]))   //  write the first word until a space
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
    while (str[j] != '\0' && is_space(str[j]))    // skip the spaces
        j++;  // stores the position of the first letter of the first word
    i = j;  // start from the first letter of the first word
    while (str[i] != '\0' && !is_space(str[i]))  // skip the first word
        i++;
    while(str[i] != '\0')
    {
        if (str[i] != '\0' && !is_space(str[i]) && is_space(str[i - 1]))   // if there is the start of the word (with a previous space (i - 1))
        {
            while (str[i] != '\0' && !is_space(str[i])) // write the word
            {
                write (1, &str[i], 1);
                i++;
            }
            write (1, " ", 1);  // write the space
        }
        i++;
    }
    first_word(str, j);  // once the str[i] is finished we write the first word with the counter j
}

int main(int argc, char **argv)
{
    if (argc > 1)
        rostring(argv[1]);
    write (1, "\n", 1);
    return (0);
}
