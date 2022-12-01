/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:10 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/02 00:33:37 by agonelle         ###   ########.fr       */
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
	ind_cmd = 2;
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
	cmd->flags = ft_get_flag(argv);
	cmd->bin = ft_get_bin(argv, path);
	cmd->index = index;
	cmd->next_cmd = NULL;
	return (cmd);
}

void	connect_cmd(t_cmd *cmd_before, t_cmd *cmd_after)
{
	cmd_before->next_cmd = cmd_after;
}

t_cmd	*clean_front(t_cmd	*front_cmd)
{
	t_cmd	*tmp;

	ft_free_tab((void *)front_cmd->flags, ft_lensplit(front_cmd->flags));
	free(front_cmd->bin);
	tmp = front_cmd->next_cmd;
	free(front_cmd);
	return (tmp);
}
