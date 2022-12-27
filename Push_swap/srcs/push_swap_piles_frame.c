/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_piles_frame.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:19:48 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/25 19:24:37 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pi_f	*set_frame(t_pi_el **lec_a, t_pi_el **lec_b, int max_len)
{
	t_pi_f	*new_frame;

	new_frame = malloc(sizeof(*new_frame) * 1);
	new_frame->head_a = lec_a;
	new_frame->f_elem_a = *lec_a;
	new_frame->head_b = lec_b;
	new_frame->f_elem_b = *lec_b;
	new_frame->len = max_len;
	return (new_frame);
}

void	actu_frame(t_pi_f *frame, t_pi_el **lec_a, t_pi_el **lec_b)
{
	frame->head_a = lec_a;
	frame->f_elem_a = *lec_a;
	frame->head_b = lec_b;
	frame->f_elem_b = *lec_b;
}
