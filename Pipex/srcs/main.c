/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/25 23:40:14 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int test (int fd_inp, int fd_out, char *str)
{
	(void) fd_inp;
	write(fd_out, str, ft_strlen(str));
	return (0);
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
		test(fd_in, fd_out, argv[argc - 2]);
	}
	close(fd_in);
	close(fd_out);
	return (0);
}
