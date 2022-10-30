/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:24:22 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/30 17:33:35 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	ft_add_char(const char *str, int start, va_list *ap)
{
	char	c;
	
	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}
