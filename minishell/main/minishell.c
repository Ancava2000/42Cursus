/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:25:05 by acarro-v          #+#    #+#             */
/*   Updated: 2025/07/23 15:00:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//inicializar el env. Hace falta estar en +1 de shlvl y reflejar bien el directorio con pwd
//ejecutar desde la funcion esos cambios con command_name y export.

int	g_signal;

int	initialize_mini(t_mini *mini, char **av, char **envp)
{
	mini -> token_list = NULL;
	mini -> command_list = NULL;
	mini -> exit_status = -1;
	mini -> program_name = av[0];
	mini -> og_infile = dup(STDIN_FILENO);
	mini -> og_outfile = dup(STDOUT_FILENO);
	mini -> envp = envp;
	mini -> env_dict = ft_get_env_dict(envp);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_mini	mini;

	if (ac != 1 || av[1])
		return (ft_error("Just the name of the executable"));
	initialize_mini(&mini, av, envp);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ctrl_c_in_main);
		lexer(&mini);
		parser(&mini);
		execute(&mini);
		//print_commands(&mini);
	}
	return (0);
}
