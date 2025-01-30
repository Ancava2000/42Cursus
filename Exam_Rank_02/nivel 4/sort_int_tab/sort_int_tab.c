void ft_swap(int *a, int *b)
{
    int temp;  // temp is not a pointer
    
    temp = *b;  // REMEMBER THE *
    *b = *a;
    *a = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;

    while (size > 0)  // iterate all the length
    {
        i = 0;
        while (i < (size - 1))  // iterate all the numbers in each iteration of the length
        {
            if (tab[i] > tab[i + 1])
                ft_swap(&tab[i], &tab[i + 1]);    // REMEMBER THE &
            i++;
        }
        size--;
    }
}
