/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:58:46 by emilgarc          #+#    #+#             */
/*   Updated: 2025/08/17 13:29:15 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*set_env_path(t_mini *mini, t_command *cmd, char *old_pwd)
{
	char	*path;

	if (!cmd->command_name[1])
	{
		path = get_env_var_value(mini->env_dict, "HOME");
		if (!path)
			return (envpath_error(old_pwd, "cd: HOME not set\n"));
	}
	else if (ft_strncmp(cmd->command_name[1], "-", 2) == 0)
	{
		path = get_env_var_value(mini->env_dict, "OLDPWD");
		if (!path)
			return (envpath_error(old_pwd, "cd: OLDPWD not set\n"));
		printf("%s\n", path);
	}
	else
		path = cmd->command_name[1];
	return (path);
}

int	run_cd(t_mini *mini, t_command *cmd)
{
	char	*path;
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = getcwd(NULL, 0);
	path = set_env_path(mini, cmd, old_pwd);
	if (!path)
		return (1);
	if (chdir(path) != 0)
	{
		envpath_error(old_pwd, "cd: Problem with chdir or directory name.\n");
		return (1);
	}
	new_pwd = getcwd(NULL, 0);
	if (old_pwd)
		update_env_var(mini, "OLDPWD", old_pwd);
	if (new_pwd)
		update_env_var(mini, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	return (0);
}
