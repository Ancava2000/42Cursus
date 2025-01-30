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

/*
int cmp_int(void *a, void *b) 
{
    return *((int*)a) - *((int*)b); 
}

t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(t_list *begin_list)
{
    while (begin_list != NULL)
    {
        printf("%d -> ", *((int*)begin_list->data));
        begin_list = begin_list->next;
    }
    printf("NULL\n");
}

int main()
{
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 2;

    t_list *head = create_node(&num1);
    head->next = create_node(&num2);
    head->next->next = create_node(&num3);
    head->next->next->next = create_node(&num4);
    printf("Original list: ");
    print_list(head);
    int data_ref = 2;
    ft_list_remove_if(&head, &data_ref, cmp_int);
    printf("Modified list after removing 2: ");
    print_list(head);
    return (0);
}
*/
