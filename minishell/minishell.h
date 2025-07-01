/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:33 by acarro-v          #+#    #+#             */
/*   Updated: 2025/07/01 16:59:57 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//hace falta variable en comando para cada código de salida de cada comando
//variable en mini del codigo de salida ultimo ($?).
//variable del environment (envp) para expandir (<$)

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

extern int	g_signal;

typedef struct s_token
{
	char			*token_name;
	int				token_type;
	struct s_token	*next;
}			t_token;

typedef struct s_command
{
	char				**command_name;
	int					infile;
	int					outfile;
	int					pid;
	int					exit_code;
	struct s_command	*next;
}			t_command;

typedef struct s_mini
{
	t_token			*token_list;
	t_command		*simple_command;
	int				exit_status;
	char			*program_name;
	char			**envp;
}					t_mini;

int		main(int ac, char **av);
// Lexer
void	lexer(t_mini *mini);
int		count_tokens(t_mini *mini, char *line);
// Lexer utils
int		count_quotes(char *string);
int		handle_double_quotes(t_mini *mini, char **line, char **word);
int		handle_single_quotes(char **line, char **word);
int		check_syntax(char *line);
// Parser
void	parser(t_mini *mini);
// Parser utils
char	**add_word_to_array(char *word, char **array);
void	redirections(t_mini *mini, char *redirection, char *file_name, t_command *cmd);
//Heredoc
int		ft_heredoc (t_mini *mini, char *delimiter, int expander);
//Expander
int		expand_word(t_mini *mini, char **line, char **word);
char	*resolve_value(t_mini *mini, char **line);
//Signals
void	ctrl_c_signal(int sig);
void	ctrl_c_in_main(int sig);
// Utils
int		ft_error(char *message);
//void	print_tokens(t_mini *mini);
//void	print_commands(t_mini *mini);

#endif
