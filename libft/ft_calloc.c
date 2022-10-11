/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:27:21 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/10 14:28:11 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	int		int_max;

	int_max = 2147483647;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if ((int_max / size) < nmemb)
	{
		errno = ENOMEM;
		return (NULL);
	}
	res = malloc(size * nmemb);
	ft_bzero(res, size * nmemb);
	return (res);
}
