#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *pnt;

    pnt = begin_list;
    while(pnt)
    {
        (*f)(pnt -> data);
        pnt = pnt -> next;
    }
}

/*
#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
    while(*str)
        write (1, str++, 1);
}

t_list *create_node(void *data) 
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

int main() 
{
    t_list *head = create_node("Hello ");
    head->next = create_node("42 ");
    head->next->next = create_node("students ");
    head->next->next->next = create_node("and ");
    head->next->next->next->next = create_node("world!");
    ft_list_foreach(head, (void *)ft_putstr);
    write (1, "\n", 1);
    return (0);
}
*/
