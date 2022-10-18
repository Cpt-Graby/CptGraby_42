/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:58:06 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/17 17:14:44 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_next_line
{
	char	*sol;
	char	*buff;
	int		fd;
	int		count;
	int		c_in_bf;
}t_nextl;

char	*get_next_line(int fd);
char	*get_ndup(char *s, size_t n);
int		get_next_c(char *s, int start, char c);
int		get_strlen(char	*s);
#endif
