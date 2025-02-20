typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *remove;
	t_list *current;

	if (*begin_list && (*cmp)((*begin_list) -> data, data_ref) == 0)
	{
		remove = *begin_list;
		*begin_list = (*begin_list) -> next;
		free(remove);
	}
	current = *begin_list;
	while (current && current -> next)
	{
		if ((*cmp)(current -> next -> data, data_ref) == 0)
		{
			remove = current -> next;
			current -> next = current -> next -> next;
			free(remove);
		}
		current = current -> next;
	}
}
