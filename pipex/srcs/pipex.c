/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:58:51 by acarro-v          #+#    #+#             */
/*   Updated: 2025/02/11 12:49:17 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **argv, int *fd, char **envp)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		perror("\e[1;33mError opening filein\n\e[0m");
		exit(EXIT_FAILURE);
	}
	dup2(filein, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(filein);
	execute(argv[2], envp);
}

void	parent(char **argv, int *fd, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fileout == -1)
	{
		perror("\e[1;33mError opening filout\n\e[0m");
		exit(EXIT_FAILURE);
	}
	dup2(fileout, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child(argv, fd, envp);
		waitpid(pid, NULL, 0);
		parent(argv, fd, envp);
	}
	else
	{
		ft_putstr_fd("\e[1;34mError: Incorrect number of arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
