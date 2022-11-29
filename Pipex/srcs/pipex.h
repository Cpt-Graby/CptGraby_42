/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:35:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/29 09:09:29 by mura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../42lib/libft.h"
//main,c
int		ft_core_pipex(int argc, char **argv, char *envp[], int *fd);

void	ft_init_fd(int argc, char **argv, int *fd1, int *fd2);
int		ft_init_fd_out(char *path, int cas_val);
int		ft_init_fd_in(char **arg, int cas_val);
//pipex_utils
int		ft_check_bonus(char **argv);

//get_env.c
char	*ft_get_path(char *envp[]);
#endif
