/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:23:25 by kali              #+#    #+#             */
/*   Updated: 2025/04/05 08:27:23 by kali             ###   ########.fr       */
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
        ft_error("No negative numbers!", 1);
    if (!is_digit(*str))
        ft_error("Only digits!", 1);
    correct_str = str;
    while(is_digit(*str++))
        len++;
    if (len > 10)
        ft_error("Too big! INT_MAX is the limit", 1);
    return (correct_str);
}

long ft_atoi2(const char *str)
{
    long nb;
    
    nb = 0;

    str = checker(str);
    while (is_digit(*str))
    {
        nb = (nb * 10) + (*str - '0');
        str++;
    }
    if (nb > INT_MAX)
        ft_error("Too big! INT_MAX is the limit", 1);
    return (nb);
}

void    parse_av(int ac, char **av)
{
    int     i;
    long    nb;

    i = 0;
    while (++i < ac)
    {
        nb = ft_atoi2(av[i]);
        if (i == 1 && nb == 0)
            ft_error("At least you must indicate 1 philo", 1);
        else if (i == 5 && nb <= 0)
            ft_error("If there are nb of meals, indicate at least 1", 1);
        else if (i != 1 && i != 5 && nb < 60)
            ft_error("At least you must indicate 60ms timestamps", 1);
    }
}