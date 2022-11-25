/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/25 17:01:09 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		filedesc = open(path, O_APPEND);
	else
		filedesc = open(path, O_CREAT | O_WRONLY, mode);
	if (filedesc == -1)
	{
		perror("ft_init_fd - file Output");
		return (-1);
	}
	else
		return (filedesc);
}

void	ft_init_fd(int argc, char **argv, int *fd1, int *fd2)
{
	int	bonus;

	if (!ft_strncmp(argv[1], "here_doc", 15))
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

int	main(int argc, char **argv)
{
	int	fd_in;
	int	fd_out;

	if (argc < 5)
	{
		errno = EINVAL;
		perror("main.c - main");
		return (-1);
	}
	else
	{
		ft_init_fd(argc, argv, &fd_in, &fd_out);
		write(fd_out, "an error writing to standard out\n", 70);
	}
	close(fd_in);
	close(fd_out);
	return (0);
}
