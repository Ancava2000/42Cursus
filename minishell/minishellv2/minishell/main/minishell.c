/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:25:05 by acarro-v          #+#    #+#             */
/*   Updated: 2025/08/17 13:25:56 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal;

int	initialize_mini(t_mini *mini, char **av, char **envp)
{
	mini -> token_list = NULL;
	mini -> command_list = NULL;
	mini -> exit_status = 0;
	mini -> program_name = av[0];
	mini -> og_infile = dup(STDIN_FILENO);
	mini -> og_outfile = dup(STDOUT_FILENO);
	mini -> envp = envp;
	mini -> env_dict = ft_get_env_dict(envp);
	return (0);
}

void	setup_main_signals(void)
{
	signal(SIGQUIT, ctrl_quit);
	signal(SIGINT, ctrl_c_in_main);
}

int	run_minishell(t_mini *mini)
{
	char	*line;

	while (1)
	{
		setup_main_signals();
		line = readline("Minishell-> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		add_history(line);
		if (lexer(mini, line) != 0)
		{
			free(line);
			mini -> exit_status = 1;
			cleanup_arrays(mini);
			continue ;
		}
		parser(mini);
		execute(mini);
		cleanup_arrays(mini);
		free(line);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_mini	mini;

	if (ac != 1 || av[1])
		return (ft_error("Just the name of the executable"));
	initialize_mini(&mini, av, envp);
	run_minishell(&mini);
	free_mini(&mini);
	return (0);
}
