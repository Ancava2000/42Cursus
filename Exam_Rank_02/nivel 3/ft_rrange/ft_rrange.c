#include <stdlib.h>

int ft_abs(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

int     *ft_rrange(int start, int end)
{
    int length;
    int i;
    int *range;
    
    length = 0;
    i = 0;
    length = ft_abs(start - end);    // absolute numbers
    if (!(range = (int *)malloc(sizeof(int) * length + 1)))
        return (NULL);
    if (end < start)
    {
        while (end <= start)
            range[i++] = end++;
    }
    else
    {
        while (end >= start)
            range[i++] = end--;
    }
    return (range);
}
/*
#include <stdio.h>

int main()
{
    int start = -3;
    int end = 10;
    int i = 0;
    int length = 0;
    int *range;

    range = ft_rrange(start, end);
    length = ft_abs(end - start) + 1;
    while (i < length)
    {
        printf(" [%i] ", range[i]);
		i++;
	}
	printf("\n");
}
*/
