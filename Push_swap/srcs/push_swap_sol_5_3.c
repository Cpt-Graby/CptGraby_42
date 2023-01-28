/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sol_5_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:39:27 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/28 18:25:22 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_and_return(char *msg, int ret_val)
{
	ft_printf("%s", msg);
	return (ret_val);
}

int	sort_2_element(t_pi_f *frame)
{
	if (frame->f_elem_a->value < frame->f_elem_a->next->value)
		return (0);
	else
		print_and_return("sa\n", 0);
	return (-1);
}

int	sort_3_element(t_pi_f *fra)
{
	int	cond1[2];
	int	cond2;

	cond1[0] = (fra->f_elem_a->value < fra->f_elem_a->next->value);
	cond2 = (fra->f_elem_a->value < fra->f_elem_a->privious->value);
	cond1[1] = (fra->f_elem_a->next->value < fra->f_elem_a->privious->value);
	if (cond1[0] && cond2 && cond1[1])
		return (0);
	else if (cond1[0] && cond2 && !cond1[1])
	{
		swap(fra, 'a', 1);
		rotate(fra, 'a', 1);
	}
	else if (!cond1[0] && cond2 && cond1[1])
		swap(fra, 'a', 1);
	else if (cond1[0] && !cond2 && !cond1[1])
		rev_rotate(fra, 'a', 1);
	else if (!cond1[0] && !cond2 && cond1[1])
		rotate(fra, 'a', 1);
	else
	{
		swap(fra, 'a', 1);
		rev_rotate(fra, 'a', 1);
	}
	return (0);
}

int	hard_code_swap(int len_tab, char **tab_num_ascii)
{
	t_pi_f	*pile_frame;
	t_pi_el	*lec_head_a;
	t_pi_el	*lec_head_b;

	lec_head_a = get_pile_a(len_tab, tab_num_ascii);
	if (!lec_head_a)
		free_pile(&lec_head_a, len_tab - 1);
	lec_head_b = NULL;
	pile_frame = set_frame(&lec_head_a, &lec_head_b, len_tab);
	if (len_tab == 3)
		sort_2_element(pile_frame);
	else if (len_tab <= 4)
		sort_3_element(pile_frame);
	else
	{
		radix_sort(pile_frame, 0);
		if (len_tab == 5)
			sort_4_element(pile_frame, tab_num_ascii, len_tab);
		else
			sort_5_element(pile_frame, tab_num_ascii, len_tab);
	}
	free_frame(pile_frame);
	return (0);
}
