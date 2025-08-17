/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_auxiliar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:29:30 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/15 17:06:57 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ipath(char **envp)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
	{
		i++;
		if (envp[i] == NULL)
			return (pathexit());
	}
	return (i);
}

// Joins dir and cmd with a '/' in between
char	*join_path(const char *dir, const char *cmd)
{
	char	*full;
	size_t	len1;
	size_t	len2;

	len2 = ft_strlen(cmd);
	len1 = ft_strlen(dir);
	full = malloc(len1 + len2 + 2);
	if (!full)
		return (NULL);
	ft_strcpy(full, dir);
	full[len1] = '/';
	ft_strcpy(full + len1 + 1, cmd);
	return (full);
}

// Searches for cmd in PATH, returns malloc'd full path or NULL
char	*find_in_path(const char *cmd, char **envp, int i)
{
	char	*path_env;
	char	**paths;
	char	*full_path;

	i = ipath(envp);
	if (envp[i] == NULL)
		return (NULL);
	path_env = envp[i] + 5;
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			freepath(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	freepath(paths);
	return (NULL);
}
