#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
    int count = 0;
    
    if (begin_list == 0)
        return (0);
    else
    {
        while (begin_list)
        {
            begin_list = begin_list -> next;
            count++;
        }
    }
    return (count);
}

/*
t_list	*ft_create_node(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int	main(void)
{
	t_list	*head;

	head = ft_create_node("One");
    head -> next = ft_create_node("Two");
    head -> next -> next = ft_create_node("Three");
    head -> next -> next -> next = ft_create_node("Four");
    head -> next -> next -> next -> next = ft_create_node("Five");
    head -> next -> next -> next -> next -> next = ft_create_node("Six");
	printf("%d\n", ft_list_size(head));
	return (0);
}
*/