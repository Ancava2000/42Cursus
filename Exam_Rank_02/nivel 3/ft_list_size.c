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
            count++
        }
    }
    return (count);
}
