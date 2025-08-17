/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:13:10 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/15 17:13:11 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_item(t_env_dict *envp, char *var_name)
{
	size_t	var_len;

	var_len = ft_strlen(var_name);
	if (var_len == 0)
		return (NULL);
	while (envp)
	{
		if (ft_strlen(envp -> key) == var_len
			&& ft_strncmp(envp -> key, var_name, var_len) == 0)
			return (ft_strdup(envp -> value));
		envp = envp -> next;
	}
	return (ft_strdup(""));
}

t_env_dict	*create_env_node(char *envp)
{
	t_env_dict	*env_node;
	int			i;

	env_node = malloc(sizeof(t_env_dict));
	if (!env_node)
		ft_error("Error with env malloc");
	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	env_node -> key = ft_substr(envp, 0, i);
	if (envp[i] == '=')
		env_node -> value = ft_strdup(envp + i + 1);
	env_node -> prev = NULL;
	env_node -> next = NULL;
	return (env_node);
}

void	create_env_list(char *envp, t_env_dict **env_dict)
{
	t_env_dict	*env_node;
	t_env_dict	*env_list;

	env_node = create_env_node(envp);
	if (!env_node)
		ft_error("Error with env_node");
	if (*env_dict == NULL)
		*env_dict = env_node;
	else
	{
		env_list = *env_dict;
		while (env_list -> next != NULL)
			env_list = env_list -> next;
		env_node -> prev = env_list;
		env_list -> next = env_node;
	}
}

t_env_dict	*ft_get_env_dict(char **envp)
{
	int			i;
	t_env_dict	*env_dict;

	i = 0;
	env_dict = NULL;
	while (envp[i])
	{
		create_env_list(envp[i], &env_dict);
		i++;
	}
	return (env_dict);
}
