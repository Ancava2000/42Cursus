/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:00:00 by acarro-v          #+#    #+#             */
/*   Updated: 2024/04/23 10:18:26 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char uppercase(char c, unsigned int i)
{
    	if (i % 2 == 0)
        	return toupper(c);
    	else
        	return tolower(c);
}

int main ()
{
	ft_strmapi("Hello world", uppercase);   Returns: A new string resulting from the application of the function to the characters of the input string (HeLlO WoRlD). 
 	return (0);
}
*/
