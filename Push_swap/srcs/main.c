/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/08 10:58:44 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42lib/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		printf("Error \n");
		return (-1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_check_int(argv[i]))
				ft_printf("Je suis en ordre; %s\n", argv[i]);
			else
				ft_printf("NOPE: %s\n", argv[i]);
			i++;
		}
	}
}
