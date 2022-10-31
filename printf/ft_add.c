/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:24:22 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/30 17:57:37 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_1(char str)
{
	ft_putchar_fd(str, 1);
	return (1);
}

size_t	ft_add_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_add_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 1);
	return ((ft_strlen(str)));
}

size_t	ft_add_pnt(va_list ap)
{
	size_t	count;
	void	*p;
	
	count = 0;
	p = va_arg(ap, void *);
	printf("%p", p);
	ft_putstr_fd("This is a WIP. Not working yet", 1);
	return (count);
}

size_t	ft_add_num(va_list ap)
{
	int		n;
	size_t	len;

	n = va_arg(ap, int);
	len = (size_t)ft_nbrlen(n);
	ft_putnbr_fd(n, 1);
	return (len);
}		
