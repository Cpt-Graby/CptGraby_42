/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_piles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:25:56 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 13:23:07 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pi_el	*create_element(int val_2_save)
{
	t_pi_el	*nw;

	nw = malloc(sizeof(*nw) * 1);
	if (!nw)
	{
		ft_putstr_fd("Error \n", 2);
		return (NULL);
	}
	nw->value = val_2_save;
	nw->next = NULL;
	nw->privious = NULL;
	return (nw);
}

void	free_pile(t_pi_el *privious_elem)
{
	t_pi_el	*tmp;

	while (privious_elem->privious)
	{
		tmp = privious_elem;
		privious_elem = privious_elem->privious;
		free(tmp);
	}
	free(privious_elem);
}

t_pi_el	*add_elem_pile(t_pi_el *privious_elem, int val_2_save)
{
	t_pi_el	*new_element;

	new_element = create_element(val_2_save);
	if (!new_element)
	{
		free_pile(privious_elem);
		return (NULL);
	}
	new_element->privious = privious_elem;
	privious_elem->next = new_element;
	return (new_element);
}

void	link_last_2_first(t_pi_el *last_elem, t_pi_el *first_elem)
{
	last_elem->next = first_elem;
	first_elem->privious = last_elem;
}

int	remove_elem_pile(t_pi_el **head, t_pi_el *first_elem)
{
	if (first_elem != *head)
	{
		ft_putstr_fd("Error \n", 2);
		return (0);
	}
	if (first_elem->next != first_elem)
	{
		link_last_2_first(first_elem->privious, first_elem->next);
		*head = first_elem->next;
	}
	else
		*head = NULL;
	return (1);
}
