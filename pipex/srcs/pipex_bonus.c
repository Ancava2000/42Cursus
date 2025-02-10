/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:58:51 by acarro-v          #+#    #+#             */
/*   Updated: 2025/02/10 14:39:52 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child(char *argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error(0);
	pid = fork();
	if (pid == -1)
		error(0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *delimiter)
{
	int		fd[2];
	pid_t	here;
	char	*line;

	if (pipe(fd) == -1)
		error(0);
	here = fork();
	if (here == -1)
		error(0);
	if (here == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, delimiter, ft_strlen(delimiter) == 0))
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	filein;
	int	fileout;
	int	i;

	if (argc >= 5)
	{
		if (ft_strncmp (argv[1], "here_doc", 8) == 0)
		{
			if (argc < 6)
				error(1);
			i = 3;
			fileout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0777);
			here_doc(argv[2]);
		}
		else
		{
			i = 2;
			fileout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
			filein = open(argv[1], O_RDONLY, 0777);
			dup2(filein, 0);
		}
		while (i < (argc - 2))
			child(argv[i++], envp);
		dup2(fileout, 1);
		execute(argv[argc - 2], envp);
	}
	error(1);
}
