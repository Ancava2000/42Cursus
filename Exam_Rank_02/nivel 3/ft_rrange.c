#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int length;
    int i;
    int *range;
    
    length = 0;
    i = 0;
    if (end < start)
        length = ((end - start) * -1) + 1;
    else
        length = (end - start) + 1;
    if (!(range = (int *)malloc(length * sizeof(int)))
        return (NULL);
    while (i < length)
    {
        if (end < start)
            range[i] = end++;
        else
            range[i] = end--;
        i++;
    }
    return (range);
}
