/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:16:45 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/30 17:58:33 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += add_2_res(format, i, ap);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
		count++;
	}
	return (count);
}

size_t	add_2_res(const char *str, int start, va_list ap)
{
	size_t	add_count;

	add_count = 1;
	if (str[start] == '%')
		ft_putchar_fd(str[start], 1);
	else if (str[start] == 'c')
		add_count = ft_add_char(ap);
	else if (str[start + 1] == 's')
		add_count = ft_add_str(ap);
	else
		ft_putchar_fd(str[start], 1);
	return (add_count);
}
		/*
	else if (str[start + 1] == 'p')
		add_void();
	else if (str[start + 1] == 'd')
		add_decimal();
		*/
