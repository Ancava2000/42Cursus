#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t count = 0;
    
    while (*s)
    {
        while (reject[i] != '\0')
        {
            if (*s == reject[i])
            {
                if (reject[i] != '\0');
                    return (count);
            }
            i++;
        }
        i = 0;
        count++;
        s++;
    }
    return (count);
}
