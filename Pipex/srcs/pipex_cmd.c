/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:10 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/29 17:51:29 by agonelle         ###   ########.fr       */
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

	new_path = ft_strjoin("./", cmd_name);
	if (access(cmd_name, X_OK))
		return (new_path);
	return (new_path);
}
