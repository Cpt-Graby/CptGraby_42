/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/01 19:13:07 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
typedef struct s_cmd
{
	char			*bin;
	char			*flags;
	int				index;
	struct s_cmd	*next_cmd;
}					t_cmd;
*/
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
	char	**tab_path_env;
	t_cmd	*cmd;

	(void) fd;
	i = 2;
	cmd = NULL;
	tab_path_env = ft_get_path(envp);
	ft_get_cmds(cmd, argc, argv, tab_path_env);
	ft_free_tab((void *)tab_path_env, ft_lensplit(tab_path_env));
	while (i < argc - 1)
	{
		printf("%d:Not up yet\n", i);
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
		ft_core_pipex(argc, argv, envp, &fd[0]);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
