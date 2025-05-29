/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:33 by acarro-v          #+#    #+#             */
/*   Updated: 2025/05/29 14:25:19 by kali             ###   ########.fr       */
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
int		check_syntax(char *line);
// Utils
int		ft_error(char *message);
void	print_tokens(t_mini *mini);

#endif
