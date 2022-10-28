/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:16:45 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 16:22:53 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	va_list	*pap;
	char	*result;
	int		ind[4];

	ft_bzero(ind, sizeof(*ind) * 4);
	va_start(ap, format);
	pap = &ap;
	ind[2] = ft_strlen(format);
	result = ft_calloc(sizeof(*result), 1);
	if (!result)
		ind[3] = 1;
	while (ind[0] <= ind[2] && !ind[3])
	{
		if (format[ind[0]] == '%' || format[ind[0]] == '\0')
		{
			result = add_2_res(format, ind[1], result, &ap);
			ind[1] = ++ind[0] + 1;
		}
		ind[0]++;
	}
	if (!ind[3])
		ft_putstr_fd(result, 1);
	free(result);
	return (0);
}

char	*add_2_res(const char *str, int start, char *res_ac, va_list *ap)
{
	char	*tmp;
	char	*tmp_res;
	int		end;

	end = ft_n_ind(str, start, '%');
	if (str[end] == '\0' || end == 0)
		tmp = add_final(str, start, ft_strlen(str));
	else if (str[end + 1] == 'c')
		tmp = add_char(str, start, end, ap);
	else
		tmp = add_final(str, start, end + 1);
	if (!tmp)
		return (NULL);
	tmp_res = ft_transfert(res_ac, tmp);
	free(tmp);
	return (tmp_res);
}
		/*
	else if (str[i + 1] == 's')
		add_string();
	else if (str[i + 1] == 'p')
		add_void();
	else if (str[i + 1] == 'd')
		add_decimal();
		*/
