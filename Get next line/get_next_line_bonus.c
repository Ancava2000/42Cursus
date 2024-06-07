/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:07:49 by acarro-v          #+#    #+#             */
/*   Updated: 2024/06/06 14:29:14 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer, char *temp)
{
	char	*joined;

	joined = ft_strjoin(buffer, temp);
	free(buffer);
	return (joined);
}

char	*buffer_rest(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i] != '\0')
		temp[j++] = buffer[i++];
	free(buffer);
	return (temp);
}

char	*buffer_copy(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	line = 0;
	if (buffer[i] == '\0')
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(char *buffer, int fd)
{
	char	*temp;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			free(buffer);
			return (0);
		}
		temp[i] = '\0';
		buffer = ft_free(buffer, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = buffer_copy(buffer[fd]);
	buffer[fd] = buffer_rest(buffer[fd]);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd1;
	int	fd2;
	char	*line1;
	char	*line2;
 	int	i;
	
	i = 1;
	fd1 = open("aaa.txt", O_RDONLY);
 	fd2 = open("bbb.txt", O_RDONLY);
	while (i > 0)
	{
		line1 = get_next_line(fd1);
  		line2 = get_next_line(fd2);
		if (line1 == NULL || line2 == NULL)
			break ;
		printf("%s\n%s\n", line1, line2);
		free (line1);
  		free (line2);
	}
	close(fd1);
 	close(fd2);
	return (0);
}*/
