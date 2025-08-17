/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_auxiliar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:07:53 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/08 16:47:53 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Helper function to find an environment variable in the env_dict
t_env_dict	*find_env_var(t_env_dict *env_dict, char *key)
{
	t_env_dict	*current;

	current = env_dict;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0
			&& ft_strlen(current->key) == ft_strlen(key))
			return (current);
		current = current->next;
	}
	return (NULL);
}

// Helper function to get environment variable value
char	*get_env_var_value(t_env_dict *env_dict, char *key)
{
	t_env_dict	*env_var;

	env_var = find_env_var(env_dict, key);
	if (env_var)
		return (env_var->value);
	return (NULL);
}

// Helper function to update an environment variable
void	update_env_var(t_mini *mini, char *key, char *value)
{
	t_env_dict	*env_var;

	env_var = find_env_var(mini->env_dict, key);
	if (env_var)
	{
		free(env_var->value);
		env_var->value = ft_strdup(value);
	}
	else
		cd_create_env_var(mini, key, value);
}

// Helper function to create an environment variable if not exists.
void	cd_create_env_var(t_mini *mini, char *key, char *value)
{
	t_env_dict	*new_var;
	t_env_dict	*last;

	new_var = malloc(sizeof(t_env_dict));
	if (!new_var)
		ft_error("Error with env cd malloc");
	new_var->key = ft_strdup(key);
	new_var->value = ft_strdup(value);
	new_var->next = NULL;
	new_var->prev = NULL;
	if (!mini->env_dict)
		mini->env_dict = new_var;
	else
	{
		last = mini->env_dict;
		while (last->next)
			last = last->next;
		last->next = new_var;
		new_var->prev = last;
	}
}

char	*envpath_error(char *old, char *message)
{
	printf("%s", message);
	free(old);
	return (NULL);
}
