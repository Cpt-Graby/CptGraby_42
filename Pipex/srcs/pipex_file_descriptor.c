/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_descriptor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:11:09 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/26 12:33:12 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_fd(int argc, char **argv, int *fd1, int *fd2)
{
	int	bonus;

	if (!ft_strncmp(argv[1], "here_doc", ft_maxlstr(argv[1], "here_doc")))
		bonus = 0;
	else
		bonus = 1;
	*fd1 = ft_init_fd_in(argv, bonus);
	if (*fd1 == -1)
		exit(-1);
	*fd2 = ft_init_fd_out(argv[argc - 1], bonus);
	if (*fd2 == -1)
	{
		close(*fd1);
		exit(-1);
	}
}

int	ft_init_fd_in(char **arg, int cas_val)
{
	int	filedesc;

	if (!cas_val)
		filedesc = open(arg[2], O_RDONLY);
	else
		filedesc = open(arg[1], O_RDONLY);
	if (filedesc == -1)
	{
		perror("ft_init_fd - file Input");
		return (-1);
	}
	return (filedesc);
}

int	ft_init_fd_out(char *path, int cas_val)
{
	int		filedesc;
	mode_t	mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (!cas_val)
		filedesc = open(path, O_APPEND | O_WRONLY);
	else
		filedesc = open(path, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (filedesc == -1)
	{
		perror("ft_init_fd - file Output");
		return (-1);
	}
	else
		return (filedesc);
}
