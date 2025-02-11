/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:58:51 by acarro-v          #+#    #+#             */
/*   Updated: 2025/02/11 12:45:06 by acarro-v         ###   ########.fr       */
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

void	process_line(int fd[2], char *delimiter)
{
	char	*line;

	close(fd[0]);
	while (get_next_line(&line))
	{
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
	}
}

void	here_doc(int argc, char *delimiter)
{
	int		fd[2];
	pid_t	here;

	if (argc < 6)
		error(1);
	if (pipe(fd) == -1)
		error(0);
	here = fork();
	if (here == -1)
		error(0);
	if (here == 0)
		process_line(fd, delimiter);
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
			i = 3;
			fileout = open_file(argv[argc - 1], 2);
			here_doc(argc, argv[2]);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 0);
			dup2(filein, 0);
		}
		while (i < (argc - 2))
			child(argv[i++], envp);
		dup2(fileout, 1);
		execute(argv[argc - 2], envp);
	}
	error(1);
}
