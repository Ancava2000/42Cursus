void ft_swap(int *a, int *b)
{
    int temp;  // temp is not a pointer
    
    temp = *b;
    *b = *a;
    *a = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;

    while (size > 0)
    {
        i = 0;
        while (i < (size - 1))
        {
            if (tab[i] > tab[i + 1])
                ft_swap(&tab[i], &tab[i + 1]);
            i++;
        }
        size--;
    }
}
