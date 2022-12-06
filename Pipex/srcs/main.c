/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:16 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/06 17:55:05 by agonelle         ###   ########.fr       */
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

int	cmd_exe_1(t_cmd *cmd_2_ex, t_pipe *all_pipes, char *envp[])
{
	dup2(all_pipes[0].fd[0], 0);
	close(all_pipes[1].fd[0]);
	dup2(all_pipes[1].fd[1], 1);
	if (!cmd_2_ex->bin)
	{
		perror("cmd_exe_1 - command not found");
		exit(-1);
	}
	execve(cmd_2_ex->bin, cmd_2_ex->flags, envp);
	if (execve(cmd_2_ex->bin, cmd_2_ex->flags, envp) == -1)
		perror("main.c - cmd_exe_2");
	exit(-1);
}

int	cmd_exe_2(t_cmd *cmd_2_ex, t_pipe *all_pipes, char *envp[])
{
	close(all_pipes[1].fd[1]);
	dup2(all_pipes[1].fd[0], 0);
	dup2(all_pipes[0].fd[1], 1);
	if (!cmd_2_ex->bin)
	{
		perror("cmd_exe_2 - command not found");
		exit(-1);
	}
	if (execve(cmd_2_ex->bin, cmd_2_ex->flags, envp) == -1)
		perror("main.c - cmd_exe_2");
	exit(-1);
}

void	ft_core_pipex(int argc, char **argv, char *envp[], t_pipe *pipes)
{
	char	**tab_path_env;
	t_cmd	*cmd1;
	pid_t	cpid[2];

	tab_path_env = ft_get_path(envp);
	cmd1 = ft_get_cmds(argc, argv, tab_path_env);
	ft_free_tab((void *)tab_path_env, ft_lensplit(tab_path_env));
	if (pipe(pipes[1].fd) == -1)
	{
		perror("ft_core_pipex.c - pipe");
		exit(-1);
	}
	cpid[0] = fork();
	if (cpid[0] == 0)
		cmd_exe_1(cmd1, pipes, envp);
	cmd1 = clean_front(cmd1);
	cpid[1] = fork();
	if (cpid[1] == 0)
		cmd_exe_2(cmd1, pipes, envp);
	if (cpid[1] == -1)
		perror("ft_core_pipex: cmd2");
	cmd1 = clean_front(cmd1);
	clean_pipe(pipes, cmd1);
	waitpid(cpid[0], NULL, 0);
	waitpid(cpid[1], NULL, 0);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*pipes;
	int		nbr_pipe;

	if (argc != 5)
	{
		errno = EINVAL;
		perror("main.c - main - arguments");
		return (-1);
	}
	else
	{
		if (argc != 5 && !ft_check_bonus(argv))
			nbr_pipe = argc - 2;
		else
			nbr_pipe = argc - 3;
		pipes = malloc(sizeof(t_pipe) * nbr_pipe);
		ft_init_fd(argc, argv, &pipes[0].fd[0], &pipes[0].fd[1]);
		ft_core_pipex(argc, argv, envp, pipes);
		free(pipes);
	}
	return (0);
}
