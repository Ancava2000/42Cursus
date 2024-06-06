/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:09:29 by acarro-v          #+#    #+#             */
/*   Updated: 2024/06/06 16:15:50 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Function to join the contents of buffer and temp into the new variable joined
//Then, it frees the previous buffer to return the new joined with all the content
char	*ft_free(char *buffer, char *temp)
{
	char	*joined;

	joined = ft_strjoin(buffer, temp);
	free(buffer);
	return (joined);
}

/*After the line is copied, there's still an unwanted string before the '\n'
in the buffer. The first loop moves forward in the buffer until the '\n',
then it starts to copy the string after the '\n' (+1) into a temporal variable.
The buffer is freed and the temp with the rest of the string is returned*/
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

/*This function copies the string before the '\n' into the variable line,
this is the string printed in the first function. If buffer == '\n' 
it adds two (because of the '\n' and the null character)*/
static char	*buffer_copy(char *buffer)
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

/*When the read_file function starts, there is no buffer, so it's necessary to
allocate a basic memory for it. Then, it allocates enough memory
in a temp function to stored the content of the buffer_size.
In a loop the fd is read and, in the case of any error, it frees everything.
If the '\n' is found in the temp, the loop is broken.*/
static char	*read_file(char *buffer, int fd)
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	buffer = read_file(buffer, fd);
	if (buffer == 0)
	{
		free(buffer);
		return (0);
	}
	line = buffer_copy(buffer);
	buffer = buffer_rest(buffer);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("aaa.txt", O_RDONLY);
	while (i > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}
	close(fd);
	return (0);
}*/
