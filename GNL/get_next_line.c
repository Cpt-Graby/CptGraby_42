/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:13 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/20 16:52:00 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rest = update_buff(fd, rest);
	line = get_line(rest);
	return (line);
}

char	*update_buff(int fd, char *rest)
{
	int		count;
	int		flag;
	char	*sol;

	count = 1;
	flag = 1;
	sol = malloc(sizeof(*sol) * BUFFER_SIZE + 1);
	if (!rest)
		rest = malloc(sizeof(*rest) * 1);
	else if (get_next_c(rest, '\n'))
		flag = 0;
	while (count > 0 && flag)
	{
		count = read(fd, sol, BUFFER_SIZE);
		if (count == -1)
			return (NULL);
		sol[count] = '\0';
		rest = get_transf(sol, rest);
		if (get_next_c(rest, '\n'))
				flag = 0;
	}
	free(sol);
	return (rest);
}

char	*get_transf(char *s1, char *rest)
{
	char *tmp;
	
	tmp = get_join(s1, rest);
	free(rest);

	return (tmp);
}

char	*get_line(char	*buff)
{
	 char	*str;
	 int	ind;

	 ind =  get_next_c(buff, '\n');
	 str = get_ndup(buff, ind + 1);
	 return(str);
}
char clean_buff(char *buff)
{
	char	*tmp;
	int		ind;

	tmp = getndup((buff + ind + 2), get_len((buff + ind + 2)));
}
int main(void)
{
	int fd;
	char *p;

	fd = open("/Users/agonelle/Documents/GNL/test", O_RDONLY);
	p = get_next_line(fd);
	p = get_next_line(fd);
	close(fd);
	return (0);
	close(fd);
}
