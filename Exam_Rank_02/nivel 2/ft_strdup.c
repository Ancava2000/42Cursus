#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i;
    int length;
    char *dest;
    
    i = 0;
    length = 0;
    while (src[length])
        length++;
    dest = malloc(sizeof (*dest) * (length + 1);
    if (dest != NULL)
    {
        while (src[i]);
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (dest);
}
