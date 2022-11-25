/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/25 23:13:15 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int argc, char **argv)
{
	int	fd_in;
	int	fd_out;
	char	*str;

	str = "J aimerai ajouter cette deuxieme phrase";
	if (argc < 5)
	{
		errno = EINVAL;
		perror("main.c - main");
		return (-1);
	}
	else
	{
		ft_init_fd(argc, argv, &fd_in, &fd_out);
		write(fd_out, str, ft_strlen(str));
		write(1, str, ft_strlen(str));
	}
	close(fd_in);
	close(fd_out);
	return (0);
}
