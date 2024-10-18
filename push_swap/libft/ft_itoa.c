/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:34:25 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/09 13:45:10 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length_nb(int nb)
{
	int	len;

	len = 0;
	if (nb < 1)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static size_t	ft_sign_nb(int n)
{
	int	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

static char	*ft_new_str(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				length;
	int				sign;
	unsigned int	nbr;

	sign = 0;
	if (n < 0)
		sign = 1;
	length = ft_length_nb(n);
	str = ft_new_str(length);
	if (!str)
		return (NULL);
	*(str + length) = '\0';
	nbr = ft_sign_nb(n);
	while (length--)
	{
		*(str + length) = '0' + nbr % 10;
		nbr /= 10;
	}
	if (sign)
		*(str) = 45;
	return (str);
}
