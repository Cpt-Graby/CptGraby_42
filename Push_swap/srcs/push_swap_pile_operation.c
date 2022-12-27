/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:37:39 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 18:38:11 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_pi_f *frame, char pile, int print)
{
	int		tmp_value;
	t_pi_el	*secon_elem;
	t_pi_el	*tmp_first;

	if (pile == 'a')
		tmp_first = frame->f_elem_a;
	else if (pile == 'b')
		tmp_first = frame->f_elem_b;
	if (pile == 'a' && (!frame->f_elem_a || !frame->f_elem_a->next))
		return (0);
	else if (pile == 'b' && (!frame->f_elem_b || !frame->f_elem_b->next))
		return (0);
	secon_elem = tmp_first->next;
	tmp_value = tmp_first->value;
	tmp_first->value = secon_elem->value;
	secon_elem->value = tmp_value;
	if (print)
		ft_printf("s%c\n", pile);
	if (pile == 'a')
		*frame->head_a = tmp_first;
	else if (pile == 'b')
		*frame->head_b = tmp_first;
	return (1);
}

int	push(t_pi_f *frame, char pile, int print)
{
	t_pi_el	*tmp;
	t_pi_el	**tmp_head;
	t_pi_el	**tmp_next_head;

	if (pile == 'b')
	{
		tmp = frame->f_elem_a;
		tmp_head = frame->head_a;
		tmp_next_head = frame->head_b;
	}
	else if (pile == 'a')
	{
		tmp = frame->f_elem_b;
		tmp_head = frame->head_b;
		tmp_next_head = frame->head_a;
	}
	remove_elem_pile(tmp_head, tmp);
	insert_elem_pile(tmp, tmp_next_head);
	if (print)
		ft_printf("p%c\n", pile);
	if (pile == 'a')
		actu_frame(frame, tmp_next_head, tmp_head);
	else if (pile == 'b')
		actu_frame(frame, tmp_head, tmp_next_head);
	return (0);
}

int	rotate(t_pi_f *frame, char pile, int print)
{
	t_pi_el	*first;
	t_pi_el	**tmp_head;

	if (pile == 'a')
	{
		first = frame->f_elem_a;
		tmp_head = frame->head_a;
	}
	else if (pile == 'b')
	{
		first = frame->f_elem_b;
		tmp_head = frame->head_b;
	}
	first = first->next;
	*tmp_head = first;
	if (pile == 'a')
		actu_frame(frame, tmp_head, frame->head_b);
	else if (pile == 'b')
		actu_frame(frame, frame->head_b, tmp_head);
	if (print)
		ft_printf("r%c\n", pile);
	return (1);
}

int	rev_rotate(t_pi_f *frame, char pile, int print)
{
	t_pi_el	*first;
	t_pi_el	**tmp_head;

	if (pile == 'a')
	{
		first = frame->f_elem_a;
		tmp_head = frame->head_a;
	}
	else if (pile == 'b')
	{
		first = frame->f_elem_b;
		tmp_head = frame->head_b;
	}
	first = first->privious;
	*tmp_head = first;
	if (pile == 'a')
		actu_frame(frame, tmp_head, frame->head_b);
	else if (pile == 'b')
		actu_frame(frame, frame->head_b, tmp_head);
	if (print)
		ft_printf("rr%c\n", pile);
	return (1);
}
