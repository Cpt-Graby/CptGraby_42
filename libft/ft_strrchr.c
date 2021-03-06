/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:54:21 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/21 16:11:12 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t	i;
	char *cp;
	char cc;

	i = 0;
	cp = (char *)s;
	cc = (char) c;
	while (cp[i] != 0)
		i++;
	while (cp[i] != cc && i != 0)
		i--;
	if (cp[i] == cc)
		return (&cp[i]);
	return (NULL);
}
