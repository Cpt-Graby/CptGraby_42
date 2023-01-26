/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sol_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:17:10 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/26 17:33:14 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_5_element(t_pi_f *pile_frame, char **tab, int len)
{
	t_pi_f	*pile_frame_2;
	t_pi_el	*lec_head_c;

	lec_head_c = get_pile_a(len, tab);
	if (!lec_head_c)
		return (-1);
	pile_frame_2 = set_frame(&lec_head_c, pile_frame->head_b, len);
	set_index(pile_frame, pile_frame_2);
	push(pile_frame_2, 'b', 1);
	push(pile_frame_2, 'b', 1);
	sort_3_element(pile_frame_2);
	if (pile_frame_2->f_elem_b->value < pile_frame_2->f_elem_b->next->value)
		swap(pile_frame_2, 'b', 1);
	while (pile_frame_2->f_elem_b)
	{
		if (pile_frame_2->f_elem_b->index < pile_frame_2->f_elem_a->index)
			push(pile_frame_2, 'a', 1);
		else
			rotate(pile_frame_2, 'a', 1);
	}
	while (pile_frame_2->f_elem_a->index != 0)
		rotate(pile_frame_2, 'a', 1);
	free_frame(pile_frame_2);
	return (0);
}

int	sort_4_element(t_pi_f *pile_frame, char **tab, int len)
{
	t_pi_f	*pile_frame_2;
	t_pi_el	*lec_head_c;

	lec_head_c = get_pile_a(len, tab);
	if (!lec_head_c)
		return (-1);
	pile_frame_2 = set_frame(&lec_head_c, pile_frame->head_b, len);
	set_index(pile_frame, pile_frame_2);
	push(pile_frame_2, 'b', 1);
	sort_3_element(pile_frame_2);
	if (pile_frame_2->f_elem_b->value < pile_frame_2->f_elem_b->next->value)
		swap(pile_frame_2, 'b', 1);
	while (pile_frame_2->f_elem_b)
	{
		if (pile_frame_2->f_elem_b->index < pile_frame_2->f_elem_a->index)
			push(pile_frame_2, 'a', 1);
		else
			rotate(pile_frame_2, 'a', 1);
	}
	while (pile_frame_2->f_elem_a->index != 0)
		rotate(pile_frame_2, 'a', 1);
	free_frame(pile_frame_2);
	return (0);
}
