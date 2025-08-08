/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:33 by acarro-v          #+#    #+#             */
/*   Updated: 2025/08/08 13:22:13 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

extern int	g_signal;

typedef struct s_token
{
	char				*token_name;
	int					token_type;
	struct s_token		*next;
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

typedef struct s_env_dict
{
	char				*key;
	char				*value;
	struct s_env_dict	*next;
	struct s_env_dict	*prev;
}			t_env_dict;

typedef struct s_mini
{
	t_token				*token_list;
	t_command			*command_list;
	int					exit_status;
	int					og_infile;
	int					og_outfile;
	char				*program_name;
	char				**envp;
	t_env_dict			*env_dict;
}		t_mini;

int			main(int ac, char **av, char **envp);

// Lexer
int			lexer(t_mini *mini, char *line);
int			count_tokens(t_mini *mini, char *line);

// Lexer utils
int			count_quotes(char *string);
int			handle_double_quotes(t_mini *mini, char **line, char **word);
int			handle_single_quotes(char **line, char **word);
int			check_syntax(char *line);

// Parser
void		parser(t_mini *mini);

// Parser utils
char		**add_word_to_array(char *word, char **array);
void		redirections(t_mini *mini,
				char *redirection, char *file_name, t_command *cmd);

// Heredoc
int			ft_heredoc(t_mini *mini, char *delimiter, int expander);

// Expander
int			expand_word(t_mini *mini, char **line, char **word);
char		*resolve_value(t_mini *mini, char **line);

// Environment
char		*get_env_item(t_env_dict *envp, char *var_name);
t_env_dict	*ft_get_env_dict(char **envp);

// Executor
void		execute(t_mini	*mini);
void		check_redir(t_command *cmd);
void		og_redir(t_mini *mini, t_command *cmd);

//Builtings
int			mini_echo(t_mini *mini, t_command *cmd);
int			run_pwd(t_mini *mini, t_command *cmd);
int			run_unset(t_mini *mini, t_command *cmd);
int			run_env(t_mini *mini, t_command *cmd);
int			run_exit(t_mini *mini, t_command *cmd);
int			count_args(char **args);

//export
void		print_export_line(t_env_dict *node);
void		print_escaped_value(const char *value);
int			export_strcmp(const char *s1, const char *s2);
void		sort_env_array(t_env_dict **arr, int n);
int			env_dict_size(t_env_dict *env);
int			process_export_arg(t_mini *mini, char *arg);
int			process_export_assignment(t_mini *mini, char *arg, char *equal_sign);
int			process_export_name(t_mini *mini, char *arg);
int			run_export(t_mini *mini, t_command *cmd);
int			print_sorted_env(t_mini *mini);

//export but located in env archive
int			create_env_var(t_mini *mini, char *key);
int			is_valid_var_name(char *name);

//cd
int			run_cd(t_mini *mini, t_command *cmd);
char		*set_env_path(t_mini *mini, t_command *cmd, char *old_pwd);
char		*envpath_error(char *old, char *message);
void		cd_create_env_var(t_mini *mini, char *key, char *value);
void		update_env_var(t_mini *mini, char *key, char *value);
char		*get_env_var_value(t_env_dict *env_dict, char *key);
t_env_dict	*find_env_var(t_env_dict *env_dict, char *key);

// Signals
void		ctrl_d_signal(int sig);
void		ctrl_c_signal(int sig);
void		ctrl_c_in_main(int sig);

// Utils
int			ft_error(char *message);

// Free
void		cleanup_arrays(t_mini *mini);
void		free_commands(t_command *cmd);
void		free_tokens(t_token *token);
void		free_array(char	**str);
void		free_mini(t_mini *mini);

#endif
