/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:44:21 by kali              #+#    #+#             */
/*   Updated: 2025/07/28 12:22:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_dict(t_env_dict *env_dict)
{
	t_env_dict	*env_aux;

	while (env_dict)
	{
		env_aux = env_dict;
		env_dict = env_dict -> next;
		if (env_aux -> key)
			free(env_aux -> key);
		if (env_aux -> value)
			free(env_aux -> value);
		free(env_aux);
	}
}

void	free_mini(t_mini *mini)
{
	if (mini -> token_list)
		free_tokens(mini -> token_list);
	if (mini -> command_list)
		free_commands(mini -> command_list);
	if (mini -> env_dict)
		free_env_dict(mini -> env_dict);
	rl_clear_history();
	close(mini -> og_infile);
	close(mini -> og_outfile);
}