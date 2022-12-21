/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_engine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:04:14 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/21 11:30:37 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_order(t_pi_el *head, int len)
{
	int		i;
	int		value1;
	int		value2;
	t_pi_el *tmp;

	i = 0;
	tmp = head;
	while (++i < len - 1)
	{
		value1 = tmp->value;
		value2 = tmp->next->value;
		if (value1 > 0 && value2 > 0 && value1 > value2)
			return (0);
		else if (value1 < 0 && value2 < 0 && value1 > value2)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
	size_int = 31;
	while (i < size_int)
	{
		y = 0;
		while (y < len - 1)
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
		printf_piles(f_a, f_b, len);
		i++;
	}
	return (0);
}
