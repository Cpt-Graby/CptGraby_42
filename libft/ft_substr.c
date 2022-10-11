/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:40:41 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/10 11:41:36 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	tmp_l;

	if (s == NULL)
		return (NULL);
	tmp_l = ft_strlen(s);
	if (start > tmp_l)
		len = 0;
	else
	{
		tmp_l = ft_strlen(s + start);
		if (tmp_l < len)
			len = tmp_l;
	}
	dest = calloc(sizeof(*dest), len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
