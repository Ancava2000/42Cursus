#include <stdlib.h>
#include "list.h"

void ft_swap(int *a, int *b)
{
    int temp;    // there is not *
    
    temp = *b;  // REMEMBER THE *
    *b = *a;
    *a = temp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *temp;   // assign a *temp variable to store the first node
    
    temp = lst;   // stores the top of the list
    while(lst -> next != NULL)  // REMEMBER NULL
    {
        if (((*cmp)(lst -> data, lst -> next -> data)) == 0)   // to sort the list. if the function with the parameters returns 0, the swap is made
        {
            ft_swap(&lst -> data, &lst -> next -> data);   // REMEMBER THE &
            lst = temp;  // we start at the top of the list again
        }
        else  // if the function doesn't return 0, we continue with the next node
            lst = lst -> next;
    }
    lst = temp;  // finally, we return the pointer to the start of the list
    return(lst);  // returns the list from the top
}
