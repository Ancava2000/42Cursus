/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:33 by acarro-v          #+#    #+#             */
/*   Updated: 2025/05/26 13:27:37 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_token
{
	char			*token_name;
	int				token_type;
	struct s_token	*next;
}			t_token;

typedef struct s_mini
{
	t_token			*token_list;
}					t_mini;

int		main(int ac, char **av);
// Lexer
int		lexer(t_mini *mini);
int		count_quotes(char *string);
int		count_tokens(t_mini *mini, char *line);
// Utils
int		ft_error(char *message);

#endif
