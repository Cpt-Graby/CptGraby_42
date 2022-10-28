/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:55:32 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 15:02:18 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transfert(char *resu, char *s1)
{
	char	*tmp;

	tmp = ft_strjoin(resu, s1);
	free(resu);
	return (tmp);
}
