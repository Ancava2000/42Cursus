/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:02:11 by acarro-v          #+#    #+#             */
/*   Updated: 2025/02/10 14:47:39 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error(int i)
{
	if (i == 1)
		ft_putstr_fd("\e[1;34mError: Incorrect number of arguments\n\e[0m", 2);
	else if (i == 0)
	{
		perror("\033[31mError");
		exit(EXIT_FAILURE);
	}
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*part_path;
	char	*path_checker;
	int		i;

	i = 0;
	while (ft_strnstr (envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path_checker = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access (path_checker, F_OK) == 0)
			return (path_checker);
		free(path_checker);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	path = find_path(command[0], envp);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		error(0);
	}
	if (execve (path, command, envp) == -1)
		error(0);
}
