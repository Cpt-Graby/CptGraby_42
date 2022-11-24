/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/24 16:34:35 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42lib/libft.h"
#include <errno.h>
#include <fcntl.h>

void	init_fd(char **argu, int *tab, int cas_val)
{
	if (!cas_val)
		tab[0] = open(argu[2], O_RDONLY);
	else
		tab[0] = open(argu[1], O_RDONLY);
	if (tab[0] == -1)
	{
		perror("init_fd - file Input");
		exit(errno);
	}
	if (!cas_val)
		tab[1] = 0;
}

int	main(int argc, char **argv)
{
	int	fd[2];
	int	res;

	if (argc < 5)
	{
		errno = EINVAL;
		perror("main.c - main");
		return (-1);
	}
	else
	{
		if (!ft_strncmp(argv[1], "here_doc", 15))
			 init_fd(argv, &fd, 0);
		else
			init_fd(argv, &fd, 1);
	}
}
