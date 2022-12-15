/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_piles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:25:56 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/14 13:21:22 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile_elem	*create_element(int val_2_save)
{
	t_pile_elem	*nw;

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

t_pile_elem	*add_elem_pile(t_pile_elem *privious_elem, int val_2_save)
{
	t_pile_elem	*new_element;

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

void	link_last_2_first(t_pile_elem *last_elem, t_pile_elem *first_elem)
{
	last_elem->next = first_elem;
	first_elem->privious = last_elem;
}

void	free_pile(t_pile_elem *privious_elem)
{
	t_pile_elem	*tmp;

	while (privious_elem->privious)
	{
		tmp = privious_elem;
		privious_elem = privious_elem->privious;
		free(tmp);
	}
	free(privious_elem);
}

int	remove_elem_pile(t_pile_elem **head, t_pile_elem *first_elem)
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
