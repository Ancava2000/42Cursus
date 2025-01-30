#include "ft_list.h"
#include <stdlib.h>  // free

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;   // just one *
    
    if ((*begin_list == NULL) || (begin_list == NULL))
        return ;
    if(cmp((*begin_list) -> data, data_ref) == 0)  // it frees the node if the function returns 0 (when both parameters are equal, == 0)
    {
        temp = *begin_list;                        // temp is the first node
        *begin_list = (*begin_list) -> next;       // the new first node in the list is now the second
        free(temp);                                // it frees the first node
        ft_list_remove_if(begin_list, data_ref, cmp);  // it repeats the process with the second node, now the first. Until the list ends
    }
    else
        ft_list_remove_if(&((*begin_list) -> next), data_ref, cmp);   // IMPORTANT, if they aren't equal we have to continue with the next node (&)
}
