/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:06:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 10:05:27 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char	s[]= "Coool test!\n";
	ft_printf(s);
	return (0);
}
