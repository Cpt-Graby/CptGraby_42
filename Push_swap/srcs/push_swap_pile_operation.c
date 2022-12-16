/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:37:39 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/16 11:45:30 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_pile_elem *head_pile, char pile)
{
	int			tmp_value;
	t_pile_elem	*secon_elem;

	if (!head_pile || !head_pile->next)
		return (0);
	secon_elem = head_pile->next;
	tmp_value = head_pile->value;
	head_pile->value = secon_elem->value;
	secon_elem->value = tmp_value;
	ft_printf("s%c\n", pile);
	return (1);
}

int	push(t_pile_elem **head, t_pile_elem *elem, t_pile_elem **head_e, char p)
{
	t_pile_elem	*tmp;

	tmp = elem;
	if (!*head)
		return (0);
	remove_elem_pile(head, elem);
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
	ft_printf("p%c\n", p);
	return (1);
}

int	rotate(t_pile_elem **head_pile, t_pile_elem *first, char pile)
{
	first = first->next;
	*head_pile = first;
	ft_printf("r%c\n", pile);
	return (1);
}

int	rev_rotate(t_pile_elem **head_pile, t_pile_elem *first, char pile)
{
	first = first->privious;
	*head_pile = first;
	ft_printf("r%c\n", pile);
	return (1);
}
