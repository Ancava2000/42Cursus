#include <stdlib.h>

int ft_is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    else
        return (0);
}

int count_word(char *str)
{
    int word = 0;
    
    while (*str)
    {
        while (*str && ft_is_space(*str))   // skip spaces
            str++;
        if (*str && !ft_is_space(*str))
        {
            word++;                        // add to the counter of words
            while (*str && !ft_is_space(*str))  // skip the rest of the word
                str++;
        }
    }
    return (word);  // return count
}

char *count_letters(char *str)   // IMPORTANT, RETURNS CHAR *
{
    char *letters;
    int i;
    
    i = 0;
    while (str[i] && !ft_is_space(str[i]))   // count the letters of the word
        i++;
    letters = (char *)malloc(sizeof(char) * (i + 1));   // malloc of the word. char and i + 1 for the NULL
    if (!letters)
        return (NULL);
    i = 0;                // return to 0
    while (str[i] && !ft_is_space(str[i]))  // iterate each letter of the word and copy to the variable with malloc
    {
        letters[i] = str[i];
        i++;
    }
    letters[i] = '\0';
    return(letters);
}

char	**ft_split(char *str)
{
    int i;
    
    char **split = (char **)malloc(sizeof(char *) * (count_word(str) + 1));  // 1. malloc with the number of words. char * and + 1 for the null character
    if (!(split))
        return (NULL);
    i = 0;
    while(*str)
    {
        while (*str && ft_is_space(*str))  // skip the spaces
            str++;
        if (*str && !ft_is_space(*str))  // first letter of the word
        {
            split[i] = count_letters(str);  // 2. malloc with the number of letters in each word
            i++;
            while(*str && !ft_is_space(*str))  // skip the rest of the word
                str++;
        }
    }
    split[i] = '\0';  // IMPORTANT end with NULL
    return (split);
}
