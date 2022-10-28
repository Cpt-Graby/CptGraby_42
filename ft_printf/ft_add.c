/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:00:56 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 16:23:00 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_final(const char *str, int start, int end)
{
	size_t	len;
	char	*res;

	len = end - start;
	res = ft_substr(str, start, len);
	return (res);
}

char	*add_char(const char *str, int start, int end, va_list *ap)
{
	char	c[2];
	char	*res;
	char	*tmp;

	c[0] = va_arg(*ap, int);
	c[1] = '\0';
	tmp = add_final(str, start, end);
	res = ft_transfert(tmp, c);
	return (res);
}
