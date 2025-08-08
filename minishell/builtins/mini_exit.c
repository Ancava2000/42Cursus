/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:59:55 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/07 15:41:45 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Specific function for recgnicing numeric strings.
static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static void	exit_with_cleanup(t_mini *mini, int exit_code)
{
	printf("exit\n");
	free_mini(mini);
	exit(exit_code);
}

// Specific function for 2 arguments in the exit command.
static void	exit_2_args(t_mini *mini, t_command *cmd)
{
	int	exit_code;

	if (!ft_isnum(cmd->command_name[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->command_name[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit_with_cleanup(mini, 2);
	}
	exit_code = ft_atoi(cmd->command_name[1]) % 256;
	if (exit_code < 0)
		exit_code = 256 + exit_code;
	exit_with_cleanup(mini, exit_code);
}

//Function that analyces the argument and decide how to exit the program.
int	run_exit(t_mini *mini, t_command *cmd)
{
	int	exit_code;
	int	arg_count;

	arg_count = count_args(cmd->command_name);
	if (arg_count == 1)
	{
		exit_code = mini->exit_status;
		if (exit_code == -1)
			exit_code = 0;
		exit_with_cleanup(mini, exit_code);
	}
	else if (arg_count == 2)
		exit_2_args(mini, cmd);
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	return (0);
}
