/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_piles2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:23:24 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/03 17:49:23 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_pi_f *frame, int target_value)
{
	int		count;
	t_pi_el	*tmp;

	count = 0;
	tmp = frame->f_elem_a;
	while (tmp->value != target_value)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	set_index(t_pi_f *frame, t_pi_f *frame2)
{
	int		i;

	i = 0;
	while (i < frame2->len - 1)
	{
		frame2->f_elem_a->index = get_index(frame, frame2->f_elem_a->value);
		rotate(frame2, 'a', 0);
		i++;
	}
}

void	free_pile(t_pi_el **adress_elem)
{
	t_pi_el	*tmp;

	if (!adress_elem)
		return ;
	while ((*adress_elem)->next)
	{
		tmp = (*adress_elem)->next;
		(*adress_elem)->next = NULL;
		free(*adress_elem);
		(*adress_elem) = tmp;
	}
}
