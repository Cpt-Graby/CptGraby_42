/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:07:34 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/25 17:30:24 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd <= 1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rest = update_buff(fd, rest);
	if (!rest)
		return (NULL);
	line = get_res_line(rest);
	if (!line)
		return(NULL);
	rest = update_nextl(rest);
	return (line);
}

char	*update_buff(int fd, char *rest)
{
	int		count;
	int		flag;
	char	*sol;

	count = 1;
	flag = get_next_c(rest, '\n');
	sol = ft_calloc(sizeof(*sol), BUFFER_SIZE + 1);
	if (!rest)
		rest = ft_calloc(sizeof(*rest), 1);
	if (!sol || !rest)
		return (NULL);
	while (count > 0 && flag)
	{
		count = read(fd, sol, BUFFER_SIZE);
		if (count == -1)
		{
			free(sol);
			return (NULL);
		}
		sol[count] = '\0';
		rest = get_transf(sol, rest);
		flag = get_next_c(rest, '\n');
	}
	free(sol);
	return (rest);
}

char	*get_transf(char *s1, char *rest)
{
	char	*tmp;

	tmp = get_join(rest, s1);
	free(rest);
	return (tmp);
}

char	*get_res_line(char *buff)
{
	char	*str;
	int		ind;

	if (buff[0] == '\0')
		return (NULL);
	ind = get_next_c(buff, '\n');
	if (ind == 0)
		ind = get_len(buff);
	str = get_ndup(buff, ind + 2);
	return (str);
}

char	*update_nextl(char *buff)
{
	char	*tmp;
	int		ind;

	ind = get_next_c(buff, '\n');
	if (ind == 0)
		ind = get_len(buff);
	else if (ind == get_len(buff) - 1)
	{
		free(buff);
		return (NULL);
	}
	tmp = get_ndup((buff + ind), get_len((buff + ind)) + 1);
	free(buff);
	return (tmp);
}
/*
int main(void)
{
	int fd;
	char *p;

//	fd = open("/home/xxx/Desktop/CptGraby_42/GNL/test", O_RDONLY);
//	fd = open("/Users/xxx/Documents/GNL/test", O_RDONLY);
	p = get_next_line(fd);
	printf("Le resultat est:%s\n", p);
	p = get_next_line(fd);
	printf("Le resultat est:%s\n", p);
	close(fd);
	return (0);
	close(fd);
}
*/
