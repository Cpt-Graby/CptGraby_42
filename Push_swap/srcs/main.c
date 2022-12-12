/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/09 18:15:18 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pile_order(int *pile, int len)
{
	int	i;

	i = 0;
	while (i < len && pile[i])
	{
		if (pile[i] < pile[i + 1])
			return (0);
		i++;
	}
	if (!pile[i])
		return (0);
	return (1);
}

int	core_push_swap(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	int	i;

	i = argc - 1;
	tab_a = malloc(sizeof(*tab_a) * (argc - 1));
	tab_b = malloc(sizeof(*tab_b) * (argc - 1));
	if (!tab_a)
		return (-1);
	if (!tab_b)
	{
		free(tab_a);
		return (-1);
	}	
	while (--i > 0)
		tab_a[i] = atoi(argv[i]);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error \n", 2);
		return (-1);
	}
	else
	{
		if (!ckeck_digit_flow(argc, argv))
			return (-1);
		if (!check_double(argc, argv))
			return (-1);
		if (!core_push_swap(argc, argv))
		{
			ft_putstr_fd("Error \n", 2);
			return (-1);
		}
		return (0);
	}
}
