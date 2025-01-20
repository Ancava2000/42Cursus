#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int length;
    int *range;
    int i;
    
    i = 0;
    length = abs((end - start) + 1);
    range = (int *)malloc(sizeof (int * length));
    while (i < length)
    {
        if (start < end)
        {
            range[i] = start;
            start++;
            i++;
        }
        else if (start > end)
        {
            range[i] = start;
            start--;
            i++;
        }
    }
    return (range);
}
