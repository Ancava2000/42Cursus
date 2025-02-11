/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:02:11 by acarro-v          #+#    #+#             */
/*   Updated: 2025/02/11 13:25:44 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("\e[1;34mError: Incorrect number of arguments\n\e[0m", 2);
		exit(EXIT_FAILURE);
	}
	else if (i == 0)
	{
		perror("\033[31mError");
		exit(EXIT_FAILURE);
	}
}

int	open_file(char *file, int mode)
{
	int	temp;

	if (mode == 0)
		temp = open(file, O_RDONLY, 0777);
	if (mode == 1)
		temp = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (mode == 2)
		temp = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (temp == -1)
	{
		perror("\e[1;33mError opening file\n\e[0m");
		exit(EXIT_FAILURE);
	}
	return (temp);
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

int	get_next_line(char **line)
{
	char	*buffer;
	int		nb;
	int		count;
	char	c;

	nb = 0;
	count = 0;
	buffer = malloc(sizeof(char) * 100000);
	if (!buffer)
		return (-1);
	nb = read(0, &c, 1);
	while (nb && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[count] = c;
		count++;
		nb = read(0, &c, 1);
	}
	buffer[count] = '\n';
	buffer[count + 1] = '\0';
	*line = buffer;
	free(buffer);
	return (nb);
}
