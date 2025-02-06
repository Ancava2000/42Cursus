/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:02:23 by acarro-v          #+#    #+#             */
/*   Updated: 2025/02/03 13:36:10 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// COLORS
# define RED "\033[1;91m" 
# define CYAN "\033[1;96m"
# define BLUE "\033[0;34m" 
# define PINK "\e[95m"
# define RESET "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

/* Mandatory functions */
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif
