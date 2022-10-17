/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:13 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/17 20:08:37 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
#include <string.h>   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <stdio.h>   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <fcntl.h>  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//ret[0] = read
//ret[1] = pos
//ret[2] = ind_e

char	*get_next_line(int fd)
{
	static int	l_ind;
	int			ret;
	int			pos;
	char		*buff;
	char		*sol;

	buff = malloc(sizeof(buff) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	ret = 0;
	pos = 0;
	printf("L_ind:%d ret:%d\n",l_ind, ret);
	while (ret == 0 || (pos < l_ind && (pos + BUFFER_SIZE) > l_ind))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == 0)
			return (buff);
		buff[ret] = '\0';
		pos += ret;
	}
	printf("L_ind:%d ret:%d\n",l_ind, ret);
	/*
	pos = get_next_c(buff, (l_ind % BUFFER_SIZE), '\n');
	sol = get_join("", buff, l_ind, pos);
	printf("%s", sol);
	if (!sol)
		return (NULL);
	l_ind += pos;
	while (!pos)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		pos = get_next_c(buff, (l_ind % BUFFER_SIZE), '\n');
		sol = get_join("", buff, l_ind, pos);
		if(!pos)
			l_ind += BUFFER_SIZE;
		else
			l_ind += pos;
		if(ret == 0)
			pos = 1;
	}
	free(buff);
	*/
	return (buff);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = open("/Users/agonelle/Documents/GNL/test", O_RDONLY);
	printf("\nVoici ton res:\n");
	tmp = get_next_line(i);
	printf("%s\n", tmp);
	printf("Tu es sorti\n");
	tmp = get_next_line(i);
	printf("%s\n", tmp);
	printf("Tu es sorti\n");
	tmp = get_next_line(i);
	printf("%s\n", tmp);
	printf("Tu es sorti\n");
	printf(":)\n");
	i = close(i);
	return (0);
}
