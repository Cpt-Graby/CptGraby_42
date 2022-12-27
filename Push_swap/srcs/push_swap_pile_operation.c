/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:37:39 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/26 00:27:17 by agonelle         ###   ########.fr       */
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

int	push(t_pi_el **head, t_pi_el *elem, t_pi_el **head_e, char p)
{
	t_pi_el	*tmp;

	tmp = elem;
	if (!*head)
		return (0);
	ft_printf("Berfore remove\n");
	ft_printf("pile_head_a: %p\n", *head);
	ft_printf("lec_head_a : %p\n", elem);
	ft_printf("pile_head_b: %p\n", *head_e);
	remove_elem_pile(head, elem);
	ft_printf("After remove\n");
	ft_printf("pile_head_a: %p\n", *head);
	ft_printf("lec_head_a : %p\n", elem);
	ft_printf("pile_head_b: %p\n", *head_e);

	if (!*head_e)
	{
		elem->privious = elem;
		elem->next = elem;
	}
	else
	{
		elem->next = *head_e;
		tmp = *head_e;
		if (tmp->next == tmp)
			link_last_2_first(tmp->next, elem);
		link_last_2_first(elem->next->privious, elem);
		link_last_2_first(elem, elem->next);
	}
	*head_e = elem;
	tmp = *head_e;
	if (p != 'x')
		ft_printf("p%c\n", p);
	ft_printf("pile_head_a: %p\n", *head);
	ft_printf("lec_head_a : %p\n", elem);
	ft_printf("pile_head_b: %p\n", *head_e);
	elem = *head;
	return (1);
}

int	rotate(t_pi_el **head_pile, t_pi_el *first, char pile)
{
	first = first->next;
	*head_pile = first;
	if (pile != 'x')
		ft_printf("r%c\n", pile);
	return (1);
}

int	rev_rotate(t_pi_el **head_pile, t_pi_el *first, char pile)
{
	first = first->privious;
	*head_pile = first;
	if (pile != 'x')
		ft_printf("rr%c\n", pile);
	return (1);
}
