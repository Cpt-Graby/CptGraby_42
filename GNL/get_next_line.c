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
//|| read(fd, 0, 0) < 0)
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd <= 1 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = update_buff(fd, rest);
	if (!rest)
		return (NULL);
	line = get_res_line(rest);
	rest = update_nextl(rest);
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
	if (!sol || !rest)
		return (NULL);
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
	char	*tmp;

	tmp = get_join(s1, rest);
	free(rest);
	return (tmp);
}

char	*get_res_line(char *buff)
{
	char	*str;
	int		ind;

	ind = get_next_c(buff, '\n');
	str = get_ndup(buff, ind + 1);
	return (str);
}

char	*update_nextl(char *buff)
{
	char	*tmp;
	int		ind;

	ind = get_next_c(buff, '\n');
	tmp = get_ndup((buff + ind + 2), get_len((buff + ind + 2)));
	free(buff);
	return (tmp);
}
/*
int main(void)
{
	int fd;
	char *p;

	fd = open("/home/kino/Desktop/CptGraby_42/GNL", O_RDONLY);
	p = get_next_line(fd);
	printf("%s", p);
	p = get_next_line(fd);
	close(fd);
	return (0);
	close(fd);
}
*/
