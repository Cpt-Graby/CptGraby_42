/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:16:45 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/30 17:32:43 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	ap;
	va_list	*pap;

	i = 0;
	count = 0;
	va_start(ap, format);
	pap = &ap;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += add_2_res(format, i, pap);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
		count++;
	}
	return (count);
}

size_t	add_2_res(const char *str, int start, va_list *ap)
{
	size_t	add_count;

	add_count = 1;
	if (str[start] == '%')
		ft_putchar_fd(str[start], 1);
	else if (str[start] == 'c')
		add_count = ft_add_char(str, start, ap);
	else
		ft_putchar_fd(str[start], 1);
	return (add_count);
}
		/*
	else if (str[i + 1] == 's')
		add_string();
	else if (str[i + 1] == 'p')
		add_void();
	else if (str[i + 1] == 'd')
		add_decimal();
		*/
