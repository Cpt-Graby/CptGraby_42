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
	int value;
	printf(" ========== Test one string ========== \n");
	value = ft_printf("Coool test! La suite est la-\n");
	if (printf("Coool test! La suite est la-\n") == value) 
		printf("Valide\n");
	printf(" ============== Test %%c ============ \n");
	value = ft_printf("Coool test%c La suite est la%c-\n", '!', '.');
	printf("%d", value);
	value = printf("Coool test%c La suite est la%c-\n", '!', '.');
	printf("%d", value);
	if (printf("Coool test%c La suite est la%c-\n", '!', '.') == value)
		printf("Valider\n");
	printf("\n");
	value =	ft_printf(" %c ", '0');
	if (printf(" %c ", '0') == value)
		printf("Valider\n");
	printf("\n");
	printf("\n");
	printf(" %c ", '0');
	return (0);
}
