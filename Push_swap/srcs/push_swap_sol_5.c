/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sol_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:17:10 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/30 09:25:56 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_5_element(t_pi_f *pile_frame, char **tab, int len)
{
	t_pi_f	*pile_ind;
	t_pi_el	*lec_head_c;

	lec_head_c = get_pile_a(len, tab);
	if (!lec_head_c)
		return (-1);
	pile_ind = set_frame(&lec_head_c, pile_frame->head_b, len);
	set_index(pile_frame, pile_ind);
	while (pile_ind->f_elem_a->index != 0 && pile_ind->f_elem_a->index != 1)
		rotate(pile_ind, 'a', 1);
	push(pile_ind, 'b', 1);
	while (pile_ind->f_elem_a->index != 0 && pile_ind->f_elem_a->index != 1)
		rotate(pile_ind, 'a', 1);
	push(pile_ind, 'b', 1);
	if (pile_ind->f_elem_b->index < pile_ind->f_elem_b->next->index)
		rotate(pile_ind, 'b', 1);
	sort_3_element(pile_ind);
	push(pile_ind, 'a', 1);
	push(pile_ind, 'a', 1);
	free_frame(pile_ind);
	return (0);
}

int	sort_4_element(t_pi_f *pile_frame, char **tab, int len)
{
	t_pi_f	*pile_ind;
	t_pi_el	*lec_head_c;

	lec_head_c = get_pile_a(len, tab);
	if (!lec_head_c)
		return (-1);
	pile_ind = set_frame(&lec_head_c, pile_frame->head_b, len);
	set_index(pile_frame, pile_ind);
	push(pile_ind, 'b', 1);
	sort_3_element(pile_ind);
	if (pile_ind->f_elem_b->index == 3)
	{
		push(pile_ind, 'a', 1);
		rotate(pile_ind, 'a', 1);
		return (0);
	}
	while ((pile_ind->f_elem_b->index + 1) != pile_ind->f_elem_a->index)
		rotate(pile_ind, 'a', 1);
	printf_piles(pile_ind);
	push(pile_ind, 'a', 1);
	while (pile_ind->f_elem_a->index != 0)
		rotate(pile_ind, 'a', 1);
	free_frame(pile_ind);
	return (0);
}
