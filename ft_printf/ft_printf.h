/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:06:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 16:03:29 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdio.h> 

int		ft_printf(const char *format, ...);
char	*add_2_res(const char *str, int start, char *res_ac, va_list *ap);
char	*add_final(const char *str, int start, int end);
char	*add_char(const char *str, int start, int end, va_list *ap);
char	*ft_transfert(char *resu, char *s1);
int		ft_n_ind(const char *str, int start, char c);

#endif
