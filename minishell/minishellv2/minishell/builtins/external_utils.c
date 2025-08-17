/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:03:57 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/15 17:07:13 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	envpexit(void)
{
	ft_putstr_fd("ERROR: Can't find environment variables\n", 2);
	return (0);
}

int	pathexit(void)
{
	ft_putstr_fd("ERROR: Can't find PATH= routes\n", 2);
	exit(EXIT_FAILURE);
	return (0);
}

void	freepath(char	**paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

// checks if the command is an absolute path or try to find it in PATH variable.
char	*path_handling(t_mini *mini, t_command *cmd)
{
	if (!cmd->command_name || !cmd->command_name[0])
		return (NULL);
	if (ft_strchr(cmd->command_name[0], '/'))
		return (ft_strdup(cmd->command_name[0]));
	return (find_in_path(cmd->command_name[0], mini->envp, 0));
}
