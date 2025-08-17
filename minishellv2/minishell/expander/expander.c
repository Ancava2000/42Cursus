/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:12:15 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/15 17:12:18 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*resolve_value(t_mini *mini, char **line)
{
	char	*value;
	char	*var_to_expand;
	int		i;

	if (**line == '?' && ++(*line))
		value = ft_itoa(mini->exit_status);
	else if (**line == '0' && ++(*line))
		value = ft_strdup(mini -> program_name);
	else if (**line > '0' && **line <= '9' && ++(*line))
		value = ft_strdup("");
	else
	{
		i = 0;
		var_to_expand = ft_calloc(sizeof(char), 4096);
		while (ft_isalnum(**line) || **line == '_')
			(var_to_expand)[i++] = *(*line)++;
		value = get_env_item(mini -> env_dict, var_to_expand);
		free(var_to_expand);
	}
	return (value);
}

char	*add_string_to_word(char *new_value, char *word, int new_value_length)
{
	int		word_length;
	char	*new_word;

	word_length = ft_strlen(word);
	new_word = malloc(sizeof(char) * (word_length + new_value_length + 1));
	if (!new_word)
		return (NULL);
	if (word && word_length > 0)
		ft_memcpy(new_word, word, word_length);
	if (new_value && new_value_length > 0)
		ft_memcpy(new_word + word_length, new_value, new_value_length);
	new_word[word_length + new_value_length] = '\0';
	free(word);
	return (new_word);
}

int	expand_word(t_mini *mini, char **line, char **word)
{
	int		value_length;
	char	*value;

	value = resolve_value(mini, line);
	value_length = ft_strlen(value);
	*word = add_string_to_word(value, *word, value_length);
	free(value);
	return (value_length);
}
