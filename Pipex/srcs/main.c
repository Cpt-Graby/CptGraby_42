/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/02 00:41:02 by agonelle         ###   ########.fr       */
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
typedef struct s_pipe
{
	int	pipe_in;
	int	pipe_out;
}					t_pipe;

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

int	execute_cmd(t_cmd *cmd_2_ex, int fd_in, int fd_out)
{
	pid_t	cpid;

	if (fd_in != -1)
		dup2(fd_in, 0);
	if (fd_out != -1)
		dup2(fd_out, 1);
	cpid = fork();
	if (cpid == -1)
	{
		perror("execute_cmd");
		return (EXIT_FAILURE);
	}
	else if (cpid == 0)
	{
		execve(cmd_2_ex->bin, cmd_2_ex->flags, NULL);
	}
	else
		wait(0);
	return (0);
}

int	ft_core_pipex(int argc, char **argv, char *envp[], int *fd)
{
	int		i;
	int		pipe_1[2];
	char	**tab_path_env;
	t_cmd	*cmd1;

	i = 2;
	tab_path_env = ft_get_path(envp);
	cmd1 = ft_get_cmds(argc, argv, tab_path_env);
	ft_free_tab((void *)tab_path_env, ft_lensplit(tab_path_env));
	while (i < argc - 1)
	{
		printf("%d\n", cmd1->index);
		if (cmd1->index == 1)
			execute_cmd(cmd1, fd[0], 0);
		else if (cmd1->next_cmd == NULL)
			execute_cmd(cmd1, fd[0], fd[1]);
		cmd1 = clean_front(cmd1);
		i++;
	}
	free(cmd1);
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
		perror("main.c - main - not in bonus mode");
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
