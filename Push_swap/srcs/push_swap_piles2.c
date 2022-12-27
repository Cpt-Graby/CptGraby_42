/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_piles2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:23:24 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 13:23:39 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_elem_pile(t_pi_el *element, t_pi_el **head)
{
	t_pi_el	*tmp;

	if (!*head)
	{
		element->privious = element;
		element->next = element;
	}
	else
	{
		element->next = *head;
		tmp = *head;
		if (tmp->next == tmp)
			link_last_2_first(tmp->next, element);
		link_last_2_first(element->next->privious, element);
		link_last_2_first(element, element->next);
	}
	*head = element;
}
