#include <stdlib.h>

int ft_abs(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

int     *ft_range(int start, int end)
{
    int length;
    int *range;
    int i;
    
    i = 0;
    length = ft_abs(end - start);   //absolute numbers
    range = (int *)malloc(sizeof(int) * length + 1);
    if (start < end)
    {
        while (start <= end)
        {
            range[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while (start >= end)
        {
            range[i] = start;
            start--;
            i++;
        }
    }
    return (range);
}
/*
#include <stdio.h>

int main()
{
    int start = -3;
    int end = 2;
    int i = 0;
    int length = 0;
    int *range;

    range = ft_range(start, end);
    length = ft_abs(end - start) + 1;
    while (i < length)
    {
        printf(" [%i] ", range[i]);
		i++;
	}
	printf("\n");
}
*/
