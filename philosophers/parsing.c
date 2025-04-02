/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 06:29:48 by kali              #+#    #+#             */
/*   Updated: 2025/04/02 06:24:23 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_space(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

static int is_digit(char c)
{
    return (c <= '9' && c >= '0');
}

static const char *checker(const char *str)
{
    int len;
    const char *correct_str;

    len = 0;
    while (is_space(*str))
        str++;
    if (*str == '+')
        str++;
    else if (*str == '-')
        ft_error("No negative numbers!");
    if (!is_digit(*str))
        ft_error("Only digits!");
    correct_str = str;
    while(is_digit(*str++))
        len++;
    if (len > 10)
        ft_error("Too big! INT_MAX is the limit");
    return (correct_str);
}

static long ft_atoi2(const char *str)
{
    long nb;
    
    nb = 0;
    str = checker(str);

    while (is_digit(*str))
    {
        nb = (nb * 10) + (*str - 48);
        str++;
    }
    if (nb > INT_MAX)
        ft_error("Too big! INT_MAX is the limit");
    return (nb);
}

void    parse_av(t_table *table, char **av)
{
    table -> nb_philos = ft_atoi2(av[1]);
    if (table -> nb_philos == 0)
        ft_error("At least you must indicate 1 philo");
    table -> time_to_die = ft_atoi2(av[2]) * 1e3;
    if (table -> time_to_die < 6e4)
        ft_error("At least you must indicate 60ms");
    table -> time_to_eat = ft_atoi2(av[3]) * 1e3;
    if (table -> time_to_eat < 6e4)
        ft_error("At least you must indicate 60ms");
    table -> time_to_sleep = ft_atoi2(av[4]) * 1e3;
    if (table -> time_to_sleep < 6e4)
        ft_error("At least you must indicate 60ms");
    if (av[5])
        table -> nb_meals = ft_atoi2(av[5]);
    else
        table -> nb_meals = -1;
}
