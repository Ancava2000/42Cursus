/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:45:02 by kali              #+#    #+#             */
/*   Updated: 2025/04/08 16:07:03 by kali             ###   ########.fr       */
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

int checker(const char *str, const char **correct_str)
{
    int len;

    len = 0;
    while (is_space(*str))
        str++;
    if (*str == '+')
        str++;
    else if (*str == '-')
        return (ft_error("No negative numbers!", 1));
    if (!is_digit(*str))
        return (ft_error("Only digits!", 1));
    *correct_str = str;
    while(is_digit(*str++))
        len++;
    if (len > 10)
        return (ft_error("Too big! INT_MAX is the limit", 1));
    return (0);
}

int ft_atoi2(const char *str, long *result)
{
    long nb;
    const char *parsed_str;
    
    nb = 0;
    if (checker(str, &parsed_str))
        return (1);
    while (is_digit(*parsed_str))
    {
        nb = (nb * 10) + (*parsed_str - 48);
        parsed_str++;
    }
    if (nb > INT_MAX)
        return ft_error("Too big! INT_MAX is the limit", 1);
    *result = (int)nb;
    return (0);
}

int parsing(t_table *table, char **av)
{
    if (ft_atoi2(av[1], &table->nb_philos) || table->nb_philos == 0)
        return ft_error("At least indicate one philosopher\n", 1);
    if (ft_atoi2(av[2], &table->time_to_die))
        return 1;
    if (ft_atoi2(av[3], &table->time_to_sleep))
        return 1;
    if (ft_atoi2(av[4], &table->time_to_eat))
        return 1;
    if (table->time_to_die < 60 || table->time_to_sleep < 60 || table->time_to_eat < 60)
        return ft_error("Timestamps >= 60", 1);
    if (av[5])
    {
        if (ft_atoi2(av[5], &table->nb_meals))
            return 1;
    }
    else
        table->nb_meals = -1;
    return 0;
}   