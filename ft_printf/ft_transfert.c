/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:55:32 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/27 19:08:41 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transfert(char *resu, char *s1)
{
	char	*tmp;

	tmp = ft_strjoin(rest, s1);
	free(rest);
	return (tmp);
}
