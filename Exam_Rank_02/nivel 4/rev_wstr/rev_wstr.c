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
    word = 1;  // IMPORTANT starts with 1
    while(str[i] != '\0')   // count all the string
        i++;
    while(i >= 0)
    {
        j = 0;
        while(i >= 0 && (str[i] == '\0' || is_space(str[i])))  // count until the last letter of the last word. IMPORTANT == '\0'
            i--;   // last letter of the last word
        j = i;
        while(j >= 0 && !is_space(str[j]))
            j--;   // first letter of the last word
        if (!word)
            write (1, " ", 1);
        write (1, str + j + 1, i - j);   // 1, start of the word, length of the word
        word = 0; // once we go through the first word, the following words are separated by " "
        i = j;   // IMPORTANT i = j to start from the start of the last word
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}
