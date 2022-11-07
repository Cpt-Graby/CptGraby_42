/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:09:40 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/07 11:30:38 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*update_buff(int fd, char *rest);
char	*update_nextl(char *buff);
char	*get_res_line(char *buff);
char	*get_transf(char *s1, char *rest);
char	*get_join(char *s1, char *s2);
char	*get_ndup(char *s, size_t n);
int		get_next_c(char *s, char c);
int		get_len(char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif /* GET_NEXT_LINE_H */
