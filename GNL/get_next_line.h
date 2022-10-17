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

char	*get_next_line(int fd);
int		get_next_c(char *s, int start, char c);
char	*get_join(char *s1, char *s2, int start, int end);
void	get_bzero(void *s, size_t n);
int		get_strlen(char	*s);

#endif
