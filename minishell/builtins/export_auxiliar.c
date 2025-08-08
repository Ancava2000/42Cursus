/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_auxiliar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:58:19 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/08 16:01:57 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Counts the number of environment variables in the linked list
int	env_dict_size(t_env_dict *env)
{
	int	size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

//Custom strcmp function to compare environment variable keys
int	export_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

//Sorts environment variables by key using insertion sort
void	sort_env_array(t_env_dict **arr, int n)
{
	int			i;
	int			j;
	t_env_dict	*tmp;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (export_strcmp(arr[i]->key, arr[j]->key) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

//Prints value with backslash escaping for double quotes and backslashes
void	print_escaped_value(const char *value)
{
	int	i;

	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		if (value[i] == '"' || value[i] == '\\')
			printf("\\%c", value[i]);
		else
			printf("%c", value[i]);
		i++;
	}
}

//Prints a single environment variable in export format
void	print_export_line(t_env_dict *node)
{
	if (!node || !node->key)
		return ;
	printf("declare -x %s", node->key);
	if (node->value)
	{
		printf("=\"");
		print_escaped_value(node->value);
		printf("\"");
	}
	printf("\n");
}
