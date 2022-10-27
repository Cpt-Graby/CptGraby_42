/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:16:45 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/27 19:26:00 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libprintf.h"

// cspdiuxX%
int ft_printf(char *format, ...)
{
	va_list	ap;
	char	*result;
	size_t	ind;
	size_t	last_ind;
	int		err;
	
	va_start(ap, format);
	ind = 0;
	last_ind = 0;
	len = ft_strlen(format);
	err = 0;
	result = ft_calloc(sizeof(*result), 1);
	if (!resultat)
		err = 1;
	while (i <= len && !err)
	{
		if (format[i] == '%' || format[i] == '\0')
		{
			result = add_2_res(format, last_ind, i, result);
			if (!result)
				err = 1;
			last_ind = ++ind + 1;
		}
		i++;
	}
	if (!err)
		ft_putstr_fd(result, 1);
	free(result);
	return (0);
}

char	*add_2_res(char *str, int start, int end, char *res_ac) 
{
	char	*tmp;
	char	*tmp_res;
	size_t	len;	

	len = end - start; // attention peut etre un 1 necessaire
	if (!str[i])
		tmp = add_final();
		/*
	else if (str[i + 1] == 'c')
		add_char();
	else if (str[i + 1] == 's')
		add_string();
	else if (str[i + 1] == 'p')
		add_void();
	else if (str[i + 1] == 'd')
		add_decimal();
		*/
	tmp_res = ft_transfert(res_ac, tmp);
	free(tmp);
	free(res_ac);
	return (tmp_res);
}

char	*add_final(char *str, int start, int end)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = end - start;
	res = ft_substr(str, start, len);
	return (res);	
}
