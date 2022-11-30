/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:10 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/30 16:58:49 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_cmds(t_cmd	*cmd1, int argc, char **argv, char **env_paths)
{
	int		bonus;
	int		ind_cmd;
	t_cmd	*cmd_ini;
	t_cmd	*cmd_next;
	int		i;

	bonus = 1;
	ind_cmd = 1;
	i = 1;
	if (argc != 5)
		bonus = ft_check_bonus(argv);
	if (!bonus)
		ind_cmd += 1;
	cmd1 = set_cmd(argv[ind_cmd], env_paths, i);
	cmd_ini = cmd1;
	ind_cmd += 1;
	while (ind_cmd < argc - 1)
	{
		cmd_next = set_cmd(argv[ind_cmd], env_paths, i);
		connect_cmd(cmd_ini, cmd_next);
		cmd_ini = cmd_next;
		ind_cmd++;
		i++;
	}
}

t_cmd	*set_cmd(char *argv, char **path, int index)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd) * 1);
	cmd->bin = ft_get_bin(argv, path);
	printf("bin:%s \n", cmd->bin)// todo check why null
	//cmd->flags;
	cmd->index = index;
	cmd->next_cmd = NULL;
	return (cmd);
}

void	connect_cmd(t_cmd *cmd_before, t_cmd *cmd_after)
{
	cmd_before->next_cmd = cmd_after;
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
		perror("ft_get_bin - command not found");
	}
	return (NULL);
}
