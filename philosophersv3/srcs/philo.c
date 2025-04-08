/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:41:47 by kali              #+#    #+#             */
/*   Updated: 2025/04/08 15:44:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_table table;

    if(ac == 5 || ac == 6)
    {
        if (parsing(&table, av))
            return (1);
        init_table(&table);
        ft_clean(&table);
    }
    else
    ft_error("Wrong number of arguments\n"
        GREEN"Correct is:\n5: nb of philos\n800: time to die\n200: time to eat\n200: time to sleep\n[5]: nb of meals\n"RESET, 1);
    return (0);
}