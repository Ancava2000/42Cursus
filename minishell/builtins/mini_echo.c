/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:06:25 by kali              #+#    #+#             */
/*   Updated: 2025/08/08 15:24:49 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_valid_n_option(char *arg)
{
	int	j;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	j = 1;
	while (arg[j])
	{
		if (arg[j] != 'n')
			return (0);
		j++;
	}
	return (1);
}

int	mini_echo(t_mini *mini, t_command *cmd)
{
	int	i;
	int	n_option;

	(void)mini;
	i = 1;
	n_option = 0;
	while (cmd->command_name[i] && is_valid_n_option(cmd->command_name[i]))
	{
		n_option = 1;
		i++;
	}
	while (cmd -> command_name[i])
	{
		write(1, cmd -> command_name[i], ft_strlen(cmd -> command_name[i]));
		if (cmd->command_name[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!n_option)
		write(1, "\n", 1);
	return (0);
}
