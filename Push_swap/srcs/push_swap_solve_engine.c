/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_engine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:04:14 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/24 15:38:32 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort(t_pi_el **fh_a, t_pi_el *f_a, t_pi_el *f_b, int len)
{
	int		y;
	int		i;

	i = 0;
	while (i < SIZE_BIT)
	{
		y = -1;
		while (++y < len - 1)
		{
			if (!(f_a->value & (1 << i)))
				push(&f_a, f_a, &f_b, 'b');
			else
				rotate(&f_a, f_a, 'a');
		}
		while (f_b)
			push(&f_b, f_b, &f_a, 'a');
		if (check_order_after_radix(f_a, len))
		{
			while (f_a->privious->value < 0)
				rev_rotate(&f_a, f_a, 'a');
			*fh_a = f_a;
			return (0);
		}
		i++;
	}
	*fh_a = f_a;
	return (0);
}

int	check_order_after_radix(t_pi_el *head, int len)
{
	int		i;
	int		value1;
	int		value2;
	t_pi_el	*tmp;

	i = 0;
	tmp = head;
	while (++i < len - 1)
	{
		value1 = tmp->value;
		value2 = tmp->next->value;
		if (value1 > 0 && value2 > 0 && value1 > value2)
			return (0);
		else if (value1 < 0 && value2 > 0)
			return (0);
		else if (value1 <= 0 && value2 < 0 && value1 > value2)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
