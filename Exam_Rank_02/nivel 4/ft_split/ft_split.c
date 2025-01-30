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
        while (*str && ft_is_space(*str))
            str++;
        if (*str && !ft_is_space(*str))
        {
            word++;
            while (*str && !ft_is_space(*str))
                str++;
        }
    }
    return (word);
}

char *count_letters(char *str)
{
    char *letters;
    int i;
    
    i = 0;
    while (str[i] && !ft_is_space(str[i]))
        i++;
    letters = (char *)malloc(sizeof(char) * (i + 1));
    if (!letters)
        return (NULL);
    i = 0;
    while (str[i] && !ft_is_space(str[i]))
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
    
    char **split = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
    if (!(split))
        return (NULL);
    i = 0;
    while(*str)
    {
        while (*str && ft_is_space(*str))
            str++;
        if (*str && !ft_is_space(*str))
        {
            split[i] = count_letters(str);
            i++;
            while(*str && !ft_is_space(*str))
                str++;
        }
    }
    split[i] = '\0';
    return (split);
}
