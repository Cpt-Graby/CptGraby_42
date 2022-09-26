/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:15:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/19 12:10:50 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*cp1;
	char	*cp2;

	i = 0;
	cp1 = (char*)s1;
	cp2 = (char*)s2;
	while (cp1[i] && cp2[i] && cp1[i] == cp2[i] && i < n)
		i++;
	return (cp1[i] - cp2[i]);
}
