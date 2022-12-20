/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_engine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:04:14 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/16 18:28:19 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve_engine(t_pi_el *first_a, t_pi_el *first_b, int len)
{
	(void) first_a;
	(void) first_b;
	(void) len;
	return (0);
}

int	radix_sort(t_pi_el *f_a, t_pi_el *f_b, int len)
{
	int	i;
	int	y;
	int	size_int;
	int	check;

	i = 0;
	y = 0;
	size_int = 4;
	while (i < size_int)
	{
		y = 0;
		while (y < len)
		{
			check = f_a->value & (1 << i);
			if (!check)
				push(&f_a, f_a, &f_b, 'b');
			else
				rotate(&f_a, f_a, 'a');
			y++;
		}
		while (f_b)
			push(&f_b, f_b, &f_a, 'a');
		//printf_piles(f_a, f_b, len);
		//ft_printf("===============\n");
		i++;
	}
	return (0);
}
