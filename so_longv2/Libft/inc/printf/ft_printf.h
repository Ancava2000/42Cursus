/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:57:21 by acarro-v          #+#    #+#             */
/*   Updated: 2024/05/07 15:00:25 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);

/* format functions*/
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_printptr_pf(unsigned long long ptr);
int	ft_putdigit_pf(long int num, int base, char c);

#endif