#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    int i;
    int coun;
    
    while (*s)
    {
        while (*s != accept[i])
            i++;
        if (accept[i] = '\0')
            return (count);
        i = 0;
        s++;
        count++;
    }
    return (count);
}
