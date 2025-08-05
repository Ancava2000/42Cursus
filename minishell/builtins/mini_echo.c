/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:06:25 by kali              #+#    #+#             */
/*   Updated: 2025/07/26 14:43:25 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_echo(t_mini *mini, t_command *cmd)
{
	int	i;
	int	n_option;

	(void)mini;
	i = 1;
	n_option = 0;
	if (cmd -> command_name[i] && cmd -> command_name[i][0] == '-' &&
		cmd -> command_name[i][1] == 'n' && cmd -> command_name[i][2] == '\0')
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
