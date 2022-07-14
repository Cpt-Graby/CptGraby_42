/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:26:00 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/13 15:36:48 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	cp[n];

	i = 0;
	while (i < n)
	{
		cp[i] = *(unsigned char *)(src + i); 
		i++;
	}

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = cp[i]; 
		i++;
	}
	return (dest);
}