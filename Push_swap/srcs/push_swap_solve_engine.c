/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_engine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:04:14 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 14:38:21 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bits(t_pi_f *frame, int index)
{
	int		y;
	int		check;
	t_pi_el	*f_a;

	y = -1;
	printf("frame->f_elem_a%p\n", frame->f_elem_a);
	printf("f_a:%p\n", f_a);
	f_a = frame->f_elem_a;
	while (++y < (frame->len - 1))
	{
		check = f_a->value;
		if (!(check & (1 << index)))
			push(frame, 'b', 1);
		else
			rotate(&f_a, f_a, 'a');
	}
	frame->f_elem_a = f_a;
	printf("%p\n", frame->f_elem_a);
	printf_piles(frame);
}

int	radix_sort(t_pi_f *frame)
{
	int		i;

	i = 0;
	//while (i < SIZE_BIT)
	while (i < 3)
	{
		sort_bits(frame, i);
		while (frame->f_elem_b)
			push(frame, 'a', 1);
		if (check_order_after_radix(frame->f_elem_a, frame->len))
		{
			while (frame->f_elem_a->privious->value < 0)
				rev_rotate(frame->head_a, frame->f_elem_a, 'a');
			*(frame->head_a) = frame->f_elem_a;
			return (0);
		}
		i++;
	}
	*frame->head_a = frame->f_elem_a;
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
