/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:58:06 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/19 17:16:38 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//#include <stdio.h>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

typedef struct s_next_line
{
	char	*sol;
	char	*buff;
	int		count;
	int		c_in_bf;
}t_nextl;

char	*get_next_line(int fd);
void	up_struc(int fd,char *buff, t_nextl *n);
char	*check_rest(char *rest, t_nextl *n);
char	*get_core(int fd, char *rest, t_nextl *n, char *buff);
char	*term_struc(t_nextl *n);
char	*get_join(char *s1, char *s2);
char	*get_ndup(char *s, size_t n);
int		get_next_c(char *s, char c);
int		get_strlen(char	*s);

#endif
