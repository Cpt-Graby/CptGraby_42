/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:29:23 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/14 15:28:45 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_piles(t_pile_elem **head_a, t_pile_elem **head_b, int len)
{
	int			i;
	t_pile_elem	*tmp_a;
	t_pile_elem	*tmp_b;

	if (head_a)
		tmp_a = *head_a;
	if (head_b)
		tmp_b = *head_b;
	i = 0;
	while (i < len)
	{
		printf_heads(head_a, head_b);
		if (head_a)
		{
			tmp_a = tmp_a->next;
			head_a = &tmp_a;
		}
		if (head_b)
		{
			tmp_b = tmp_b->next;
			head_b = &tmp_b;
		}
		i++;
	}
	ft_printf("- -\na b\n");
}

void	printf_heads(t_pile_elem **head_a, t_pile_elem **head_b)
{
	t_pile_elem	*tmp_a;
	t_pile_elem	*tmp_b;

	if (head_a)
		tmp_a = *head_a;
	if (head_b)
		tmp_b = *head_b;
	if (!head_a)
		ft_printf("  %d\n", tmp_a->value, tmp_b->value);
	else if (!head_b)
	{
		ft_printf("%d  \n", tmp_a->value);
	}
	else
	{
		ft_printf("%d %d\n", tmp_a->value, tmp_b->value);
	}
}
