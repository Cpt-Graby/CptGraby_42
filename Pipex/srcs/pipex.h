/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:35:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/02 00:31:30 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../42lib/libft.h"

typedef struct s_cmd
{
	char			*bin;
	char			**flags;
	int				index;
	struct s_cmd	*next_cmd;
}					t_cmd;

//main,c
int		ft_core_pipex(int argc, char **argv, char *envp[], int *fd);
//pipex_filedescriptor
void	ft_init_fd(int argc, char **argv, int *fd1, int *fd2);
int		ft_init_fd_out(char *path, int cas_val);
int		ft_init_fd_in(char **arg, int cas_val);
//pipex_utils
int		ft_check_bonus(char **argv);
char	*ft_pathmaker(char *init_path, char *end_path);
//get_env.c
char	**ft_get_path(char *envp[]);
char	*ft_get_bin(char *cmd_name, char **tab_env);
//pipex_cmd.c
void	connect_cmd(t_cmd *cmd_before, t_cmd *cmd_after);
t_cmd	*set_cmd(char *argv, char **path, int index);
void	ft_get_cmds(t_cmd	*cmd1, int argc, char **argv, char **env_paths);
t_cmd	*clean_front(t_cmd	*front_cmd);
//pipex_parsing.c
char	*ft_get_bin(char *cmd_name, char **tab_env);
char	**ft_get_flag(char *format);
#endif
