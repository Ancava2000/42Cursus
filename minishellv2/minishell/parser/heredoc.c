/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:10:38 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/17 13:24:42 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	expand_heredoc_word(t_mini *mini, char **line, char **word)
{
	int		value_length;
	char	*value;
	char	*temp;

	value = resolve_value(mini, line);
	value_length = ft_strlen(value);
	temp = *word;
	*word = ft_strjoin(temp, value);
	free(value);
	free(temp);
	return (value_length);
}

char	*expand_heredoc(t_mini *mini, char **line)
{
	char	*word;
	int		i;

	word = ft_calloc(sizeof(char), 4096);
	i = 0;
	if (!word)
		return (NULL);
	while (**line)
	{
		if (**line == '$' && (*(*line + 1) == '?'
				|| ft_isalnum(*(*line + 1))) && ++*line)
			i += expand_heredoc_word(mini, line, &word);
		else
			word[i++] = *(*line)++;
	}
	return (word);
}

void	heredoc_child(t_mini *mini, char *delimiter, int fd[2], int expander)
{
	int		size;
	char	*line;

	signal(SIGINT, SIG_DFL);
	size = ft_strlen(delimiter);
	close(fd[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(line, delimiter, size + 1))
		{
			free(line);
			break ;
		}
		if (expander)
			line = expand_heredoc(mini, &line);
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	exit(0);
}

int	ft_heredoc(t_mini *mini, char *delimiter, int expander)
{
	int	fd[2];
	int	pid;
	int	status;

	status = 0;
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		heredoc_child(mini, delimiter, fd, expander);
	else
	{
		signal(SIGINT, ctrl_c_signal);
		waitpid(pid, &status, 0);
	}
	close(fd[1]);
	return (fd[0]);
}
