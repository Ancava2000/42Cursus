/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:06:41 by kali              #+#    #+#             */
/*   Updated: 2025/06/23 16:18:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirections(char *redirection, char *file_name, t_command *cmd)
{
	int fd;

	fd = 0;
	if (ft_strncmp(redirection, "<", 2) == 0)
		fd = open(file_name, O_RDONLY);
	else if (ft_strncmp(redirection, ">", 2) == 0)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (ft_strncmp(redirection, ">>", 3) == 0)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		ft_error("Error opening file");
	if (*redirection == '<')
		cmd -> infile = fd;
	else
		cmd -> outfile = fd;
}

char	**add_word(char *word, char **array)
{
	int		size;
	char	**new_array;

	size = 0;
	while (array && array[size])
		size++;
	new_array = malloc(sizeof(char *) * (size + 2));
	if (!new_array)
		return (NULL);
	ft_memcpy(new_array, array, sizeof(char *) * size);
	new_array[size] = strdup(word);
	new_array[size + 1] = NULL;
	free(array);
	return (new_array);
}
