/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:10 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/29 18:56:15 by mura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*set_cmd(char *argv, char **path, int index)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd) * 1);
	cmd->index = index;
	cmd->next_cmd = NULL;
	return (cmd);
}

char	*ft_get_bin(char *cmd_name, char **tab_env)
{
	char	*new_path;
	int		i;

	if (ft_strncmp(cmd_name, "./", 3))
	{
		if (access(cmd_name, X_OK) != -1)
			return (cmd_name);
	}
	else
	{
		i = 0;
		while (tab_env[i])
		{
			new_path = ft_strjoin(tab_env[i], cmd_name);
			if (!new_path)
				perror("pipex_cmd.c - ft_get_bin");
			if (new_path && access(new_path, X_OK) != -1)
				return (new_path);
			free(new_path);
			i++;
		}
		perror("ft_get_bin - command not found ");
	}
	return (NULL);
}
