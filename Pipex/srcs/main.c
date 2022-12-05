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
typedef struct s_pipe
{
	int	r_end;
	int	w_end;
}		t_pipe;
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
		if (cmd_2_ex->next_cmd)
			cpid = fork();
		execve(cmd_2_ex->bin, cmd_2_ex->flags, NULL);
	}
	else
		wait(0);
	return (0);
}

int	ft_core_pipex(int argc, char **argv, char *envp[], t_pipe *pipes)
{
	int		i;
	int		pipe_1[2];
	char	**tab_path_env;
	t_cmd	*cmd1;
	pid_t	cpid;

	i = 2;
	tab_path_env = ft_get_path(envp);
	cmd1 = ft_get_cmds(argc, argv, tab_path_env);
	ft_free_tab((void *)tab_path_env, ft_lensplit(tab_path_env));
	while (i < argc - 1)
	{
		if (cmd1->next_cmd)
			cpid

		cmd1 = clean_front(cmd1);
		i++;
	}
	free(cmd1);
	return (0);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*pipes;
	int		nbr_pipe;

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
		if (argc != 5 && !ft_check_bonus(argv))
			nbr_pipe = argc - 2;
		else
			nbr_pipe = argc - 3;
		pipes = malloc(sizeof(t_pipe) * nbr_pipe);
		ft_init_fd(argc, argv, pipes[0].r_end, pipes[0].w_end);
		ft_core_pipex(argc, argv, envp, pipes);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
