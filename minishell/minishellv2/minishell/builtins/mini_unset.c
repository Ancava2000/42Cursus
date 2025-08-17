/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:01:40 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/14 13:13:39 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* Removes an environment variable from the environment dictionary
and actualices de env var list. Returns 0 on success, 1 on error */
static int	remove_env_var(t_mini *mini, char *key)
{
	t_env_dict	*env_var;

	if (!is_valid_var_name(key))
	{
		ft_putstr_fd("unset: '", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	env_var = find_env_var(mini->env_dict, key);
	if (env_var)
	{
		if (env_var->prev)
			env_var->prev->next = env_var->next;
		else
			mini->env_dict = env_var->next;
		if (env_var->next)
			env_var->next->prev = env_var->prev;
		free(env_var->key);
		if (env_var->value)
			free(env_var->value);
		free(env_var);
	}
	return (0);
}

/* Removes variables from the environment.
Returns 0 on success, 1 if any argument is an invalid identifier. */
int	run_unset(t_mini *mini, t_command *cmd)
{
	int	i;
	int	status;

	status = 0;
	i = 1;
	if (!cmd->command_name[i])
		return (0);
	while (cmd->command_name[i])
	{
		if (remove_env_var(mini, cmd->command_name[i]) != 0)
			status = 1;
		i++;
	}
	return (status);
}
