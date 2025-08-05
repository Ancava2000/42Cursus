/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:01:09 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/05 13:25:56 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


//This function retrieves and prints the current working directory using getcwd.
//If it fails, it prints an error message and returns 1; otherwise, it returns 0
int	run_pwd(t_mini *mini, t_command *cmd)
{
	char	*cwd;

	(void)mini;
	(void)cmd;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
