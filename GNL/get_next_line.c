/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:13 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/19 17:23:32 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	t_nextl		*n;
	char		*sol;
	char		buff[BUFFER_SIZE];

	if (rest && get_next_c(rest, '\n'))
		return (check_rest(rest, n));
	up_struc(fd, buff, n);
	if (n->count == -1)
		return (NULL);
	if (n->count == 0)
		return (rest);
	sol = get_core(fd, rest, n, buff);
	if (!sol)
		return (NULL);
	printf("%s\n", sol);
	printf("%s\n", rest);
	return (sol);
}

char	*get_core(int fd, char *rest, t_nextl *n, char *buff)
{
	char	*solu;
	char	*tmp;
	
	if (rest && get_next_c(rest, '\n'))
		return (check_rest(rest, n));
	while (!n->c_in_bf && n->count > 0)
	{
		n->sol = get_ndup(buff, BUFFER_SIZE);
		tmp = get_join(rest, n->sol);
		free(rest);
		rest = get_ndup(tmp, get_strlen(tmp));
		free(tmp);
		up_struc(fd, buff, n);
		free(n->sol);
	}
	n->sol = get_ndup(buff, n->c_in_bf + 1);
	solu = get_join(rest, n->sol);
	free(rest);
	rest = get_ndup((n->buff + get_next_c(rest, '\n') + 1), get_strlen(rest));
	printf("coucou%s\n", rest);
	return (solu);
}

char	*check_rest(char *rest, t_nextl *n)
{
	char	*solu;
	int		ind;

	ind = get_next_c(rest, '\n');
	solu = get_ndup(rest, ind);
	if (!solu)
		return (NULL);
	n->sol = get_ndup((rest + ind + 1), get_strlen(rest + ind + 1));
	free(rest);
	rest = get_ndup(n->sol, get_strlen(n->sol));
	free(n->sol);
	return (solu);
}

void	up_struc(int fd,char *buff, t_nextl *n)
{
	n->count = read(fd, buff, BUFFER_SIZE);
	buff[n->count] = '\0';
	n->c_in_bf = get_next_c(buff, '\n');
}

char	*term_struc(t_nextl *n)
{
	free(n->sol);
	free(n);
	return (NULL);
}

int main(void)
{
	int fd;
	char *p;

	fd = open("/Users/agonelle/Documents/GNL/test1", O_RDONLY);
	p = get_next_line(fd);
	printf("test\n");
	printf("%s", p);
	p = get_next_line(fd);
	printf("%s", p);
	close(fd);
	return (0);
	close(fd);
}
