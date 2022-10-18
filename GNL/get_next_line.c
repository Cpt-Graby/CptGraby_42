/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:13 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/17 20:15:28 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	t_nextl		*n;

	next = malloc(sizeof(*next) * 1);
	n->count = read(fd, n->buff, BUFFER_SIZE);
	n->buff[n->count] = '\0';
	if (n->count == -1 || n->count == 0)
		return (rest);
	n->c_in_bf = get_next_c(n->buff, '\n');
	if (n->c_in_bf)
		n->solution = get_ndup(n->buff, c_in_bf);
	while (!n->c_in_bf)
	{
		rest = get_join(rest, n->buff, c_in_bf);
		n->count = read(fd, n->buff, BUFFER_SIZE);
		n->buff[count] = '\0';
		c_in_bf = get_next_c(n->buff, '\n');
	}
	rest = get_ndup((n->buff + n->c_in_bf), BUFFER_SIZE - n->c_in_bf + 1);
	free(n->buff);
	return (rest);
}
