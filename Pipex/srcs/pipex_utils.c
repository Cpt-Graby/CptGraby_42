/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:48:33 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/06 17:54:48 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_bonus(char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", ft_maxlstr(argv[1], "here_doc")))
		return (0);
	else
		return (1);
}

char	*ft_pathmaker(char *init_path, char *end_path)
{
	char	*new_name;
	char	*new_path;

	new_name = ft_strjoin("/", end_path);
	new_path = ft_strjoin(init_path, new_name);
	if (!new_name || !new_path)
	{
		perror("pipex_utils.c - ft_pathmaker");
		exit(errno);
	}
	free(new_name);
	return (new_path);
}

void	clean_pipe(t_pipe *pipes, t_cmd *cmd)
{
	close(pipes[0].fd[0]);
	close(pipes[0].fd[1]);
	close(pipes[1].fd[0]);
	close(pipes[1].fd[1]);
	free(cmd);
}
