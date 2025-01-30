#include <stdlib.h>
#include "list.h"

void ft_swap(int *a, int *b)
{
    int temp;
    
    temp = *b;
    *b = *a;
    *a = temp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *temp;
    
    temp = lst;
    while(lst -> next != NULL)
    {
        if (((*cmp)(lst -> data, lst -> next -> data)) == 0)
        {
            ft_swap(&lst -> data, &lst -> next -> data);
            lst = temp;
        }
        else
            lst = lst -> next;
    }
    lst = temp;
    return(lst);
}
