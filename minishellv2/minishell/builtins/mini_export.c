/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:00:34 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/08 16:45:16 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Prints all environment variables in sorted order with export formatting
int	print_sorted_env(t_mini *mini)
{
	int			size;
	int			i;
	t_env_dict	*current;
	t_env_dict	**env_array;

	current = mini->env_dict;
	size = env_dict_size(current);
	env_array = (t_env_dict **)malloc(sizeof(t_env_dict *) * size);
	if (!env_array)
		return (ft_error("export: malloc failed"));
	i = 0;
	current = mini->env_dict;
	while (current)
	{
		env_array[i++] = current;
		current = current->next;
	}
	sort_env_array(env_array, size);
	i = 0;
	while (i < size)
		print_export_line(env_array[i++]);
	free(env_array);
	return (0);
}

int	process_export_name(t_mini *mini, char *arg)
{
	if (!is_valid_var_name(arg))
	{
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	if (!find_env_var(mini->env_dict, arg))
	{
		if (create_env_var(mini, arg) != 0)
			return (1);
	}
	return (0);
}

int	process_export_assignment(t_mini *mini, char *arg, char *equal_sign)
{
	char	*key;
	char	*value;

	key = ft_substr(arg, 0, equal_sign - arg);
	if (!is_valid_var_name(key))
	{
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(key);
		return (1);
	}
	value = ft_strdup(equal_sign + 1);
	update_env_var(mini, key, value);
	free(key);
	free(value);
	return (0);
}

int	process_export_arg(t_mini *mini, char *arg)
{
	char	*equal_sign;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
		return (process_export_name(mini, arg));
	else
		return (process_export_assignment(mini, arg, equal_sign));
}

//Main export function - handles export command with arguments
int	run_export(t_mini *mini, t_command *cmd)
{
	int	arg_count;
	int	i;
	int	status;

	status = 0;
	i = 1;
	arg_count = count_args(cmd->command_name);
	if (arg_count == 1)
		return (print_sorted_env(mini));
	while (cmd->command_name[i])
	{
		if (process_export_arg(mini, cmd->command_name[i]) != 0)
			status = 1;
		i++;
	}
	return (status);
}
