/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sol_5_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:39:27 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/25 14:56:33 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_3_element(t_pi_f *frame)
{
	int condition1;
	int condition2;
	int condition3;

	condition1 = (frame->f_elem_a->value > frame->f_elem_a->next->value);
	condition2 = (frame->f_elem_a->value < frame->f_elem_a->privious->value);
	condition3 = (frame->f_elem_a->next->value
			< frame->f_elem_a->privious->value);
	if (condition1 && condition2)
		returncondition2:wq
}

int	hard_code_swap(int len_tab, char **tab_num_ascii)
{
	t_pi_f	*pile_frame;
	t_pi_el	*lec_head_a;
	t_pi_el	*lec_head_b;

	lec_head_b = NULL;
	lec_head_a = get_pile_a(len_tab, tab_num_ascii);
	if (!lec_head_a)
	{
		free_pile(&lec_head_a, len_tab - 1);
		return (-1);
	}
	pile_frame = set_frame(&lec_head_a, &lec_head_b, len_tab);
	if (len_tab <= 4)
		sort_3_element(pile_frame);

}
