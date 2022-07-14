/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:35:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/13 16:08:39 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    i = 0;
	if ((dest < src || dest > (src + n))
    && (((dest + n) < src) || ((dest + n) > (src + n))))
        return (ft_memmove(dest, src, n));
    else
    {
        while (i < n)
        {
            *(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
            i++;
        }
        return (dest);
    }
}