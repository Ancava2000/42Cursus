/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:13:26 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/15 17:13:27 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Function to print all environment variables
int	run_env(t_mini *mini, t_command *cmd)
{
	t_env_dict	*current;
	int			arg_count;

	arg_count = count_args(cmd->command_name);
	if (arg_count > 1)
	{
		ft_putstr_fd("env: Must not have options or arguments\n", 2);
		return (1);
	}
	current = mini->env_dict;
	while (current)
	{
		if (current->value)
			printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	return (0);
}

//EXPORT Variable maker
int	create_env_var(t_mini *mini, char *key)
{
	t_env_dict	*new_var;
	t_env_dict	*last;

	new_var = malloc(sizeof(t_env_dict));
	if (!new_var)
		return (ft_error("export: malloc failed"));
	new_var->key = ft_strdup(key);
	new_var->value = NULL;
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
	return (0);
}

//Check if a variable name is valid names and contain only alphanumeric chars.
int	is_valid_var_name(char *name)
{
	int	i;

	if (!name || !*name)
		return (0);
	if (name[0] != '_' && !ft_isalpha(name[0]))
		return (0);
	i = 1;
	while (name[i])
	{
		if (name[i] != '_' && !ft_isalnum(name[i]))
			return (0);
		i++;
	}
	return (1);
}
