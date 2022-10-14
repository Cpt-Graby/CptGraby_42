/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:13 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/14 18:21:37 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <stdio.h>   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

char	*get_next_line(int fd)
{
	int	ret;
	char *buff;

	buff = calloc(sizeof(*buff), BUFFER_SIZE + 1);

	ret = read(fd, buff, BUFFER_SIZE);
	printf("%d", ret);
	return (NULL);
}

//----------------------- A SUPPRIMER -----------------------------
int main (int argc, char **argv)
{
	int	i;

	i = 3;
	if (strcmp(argv[1], "1") == 0)
		i = 1;
	else if (strcmp(argv[1], "2") == 0)
		i = 2;
	else if (strcmp(argv[1], "0") == 0)
		i = 2;
	else
		return (1);
	get_next_line(i);
	return (0);
}
