/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:32:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/19 13:13:04 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char *cpb;
	char *cpl;

	cpb = (char *)big;
	cpl = (char *)little;
	i = 0;
	if (*cpl == '\0' || cpl == NULL)
		return (cpb);
	while( cpb[i] != '\0' && i < len)
	{
		j = 0;
		while (cpl[j] == cpb[i + j] && i + j < len)
			j++;
		if (!cpl[j])
			return (&cpb[i]);
		i++;
	}
	return (NULL);
}
