/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/29 09:30:28 by mura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct s_cmd
{
	char			*bin;
	char			*flags;
	int				index;
	struct s_cmd	*next_cmd;
}					t_cmd;

int	test(int fd_inp, int fd_out, char *str)
{
	(void) fd_inp;
	write(fd_out, str, ft_strlen(str));
	return (0);
}

int	ft_execute(char	*cmd, char **flags)
{
	int	val;

	val = execve(cmd, flags, NULL);
	if (val == -1)
	{
		perror("ft_execute:");
	}
	return (-1);
}

int	ft_core_pipex(int argc, char **argv, char *envp[], int *fd)
{
	int		i;
	char	*path_env;

	(void) argv;
	(void) fd;
	i = 0;
	while (i < argc - 1)
	{
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char *envp[])
{
	int	fd[2];

	if (argc < 5)
	{
		errno = EINVAL;
		perror("main.c - main");
		return (-1);
	}
	else if (argc > 5)
	{
		errno = EINVAL;
		perror("main.c - main - not the bonus");
		return (-1);
	}
	else
	{
		ft_init_fd(argc, argv, &fd[0], &fd[1]);
		ft_core_pipex(argc, argv, envp, &fd[1]);
		test(fd[0], fd[1], argv[argc - 2]);
		printf("%s", envp[0]);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
