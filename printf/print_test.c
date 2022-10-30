/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:06:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/28 16:12:13 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf(" ========== Test one string ========== \n");
	ft_printf("Coool test! La suite est la-\n");
	printf(" ============== Test %%c ============ \n");
	ft_printf("Coool test%c La suite est la%c-\n", '!', '.');
	printf("\n");
	ft_printf(" %c ", '0');
	printf("\n");
	printf(" %c ", '0');
	return (0);
}
