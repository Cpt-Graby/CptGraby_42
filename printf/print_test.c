/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:06:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/02 09:49:38 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	int value;
	printf(" ============== Test %%p ============ \n");
	ft_printf("ft:%p \n", -1); 
	printf("-1: %p \n", -1);
	printf("Le test commence apres la comprehension");
	printf("1: %p \n", 1);
	value = printf(" %p ", -1);
	if (ft_printf(" %p ", -1) == value)
		printf("Valider\n");
	printf("\n");
	return (0);
}
