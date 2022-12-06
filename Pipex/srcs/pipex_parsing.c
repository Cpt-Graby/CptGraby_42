/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:27:19 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/06 16:28:46 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_bin(char *cmd_name, char **tab_env)
{
	char	*new_path;
	int		i;

	if (!ft_strncmp(cmd_name, "./", 3))
	{
		if (access(cmd_name, X_OK) != -1)
			return (cmd_name);
	}
	else
	{
		i = 0;
		while (tab_env[i])
		{
			new_path = ft_pathmaker(tab_env[i], cmd_name);
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

char	**ft_get_flag(char *format)
{
	char	**flags;

	flags = ft_split(format, ' ');
	if (!flags)
	{
		perror("pipex_parsing.c - ft_get_flags");
		exit(-1);
	}
	return (flags);
}
