/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:48:37 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/12 13:56:38 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	int				len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
		{
			return (NULL);
		}
		ft_strlcpy(new, s1, len + 1);
		ft_strlcat(new, s2, len + 1);
		return (new);
	}
	return (NULL);
}
