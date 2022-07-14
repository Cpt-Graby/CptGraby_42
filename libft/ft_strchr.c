/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:55:05 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/14 17:32:32 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*cp;
	unsigned char	cc;

	cp = s;
	cc = (unsigned char)c
	while (*cp != 0 && *cp != cc)
		cp++
	if (*cp == cc)
		return (cp);
	else
		return (NULL);
}