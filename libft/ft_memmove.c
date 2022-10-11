/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:26:00 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/11 13:05:38 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cp_s;
	unsigned char	*cp_d;

	if (n == 0)
		return (dest);
	cp_s = (unsigned char *) src;
	cp_d = (unsigned char *) dest;
	if ((cp_s < cp_d && (cp_s + n) > cp_d))
	{
		while (n--)
			cp_d[n] = cp_s[n];
		cp_d[n] = cp_s[n];
	}
	else
		ft_memcpy(cp_d, cp_s, n);
	return (dest);
}
