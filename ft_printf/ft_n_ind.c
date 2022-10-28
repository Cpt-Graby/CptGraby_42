/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_ind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:56:11 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 16:05:15 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_n_ind(const char *str, int start, char c)
{
	char	*cp;
	int		i;

	cp = (char *)str;
	i = start;
	while (cp[i] != c && cp[i])
		i++;
	if (cp[i] == c)
		return (i);
	return (0);
}		
