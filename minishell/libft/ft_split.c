/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:12:21 by acarro-v          #+#    #+#             */
/*   Updated: 2024/05/29 11:01:48 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_tokens(const char *s, char del)
{
	size_t	tokens;
	int		inside_tokens;

	tokens = 0;
	while (*s)
	{
		inside_tokens = 0;
		if (*s == del && *s)
			s++;
		while (*s != del && *s)
		{
			if (inside_tokens == 0)
			{
				++tokens;
				inside_tokens = 1;
			}
			s++;
		}
	}
	return (tokens);
}

static int	ft_free_split(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		if (i < position)
		{
			free(token_v[position]);
			i++;
		}
		free(token_v);
		return (1);
	}
	return (0);
}

static int	ft_fill(char **token_v, const char *s, char del)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == del && *s)
			s++;
		while (*s != del && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (ft_free_split(token_v, i, len + 1))
				return (1);
		}
		if (len)
			ft_strlcpy (token_v[i], s - len, len + 1);
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t			tokens;
	char			**token_v;

	if (NULL == s)
		return (NULL);
	tokens = ft_count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return (NULL);
	token_v[tokens] = NULL;
	if (ft_fill(token_v, s, c))
		return (NULL);
	return (token_v);
}
