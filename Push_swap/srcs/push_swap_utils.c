/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:29:23 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/10 11:40:31 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_cpy_in_new_tab(char **old_tab, int len)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(*tab) * len);
	i = 1;
	while (i < len)
	{
		tab[i - 1] = ft_strdup(old_tab[i]);
		i++;
	}
	tab[i - 1] = NULL;
	return (tab);
}

int	exit_message(int i)
{
	ft_putstr_fd("Error\n", 2);
	exit (i);
}

void	printf_index(t_pi_f *frame)
{
	int		i;
	t_pi_el	*tmp_a;

	if (frame->f_elem_a)
		tmp_a = frame->f_elem_a;
	else
		tmp_a = NULL;
	i = 0;
	while (i < frame->len - 1)
	{
		ft_printf("%d - %d\n", tmp_a->value, tmp_a->index);
		if (tmp_a)
			tmp_a = tmp_a->next;
		i++;
	}
	ft_printf("- -\na b\n");
}

void	printf_piles(t_pi_f *frame)
{
	int		i;
	t_pi_el	*tmp_a;
	t_pi_el	*tmp_b;

	if (frame->f_elem_a)
		tmp_a = frame->f_elem_a;
	else
		tmp_a = NULL;
	if (frame->f_elem_b)
		tmp_b = frame->f_elem_b;
	else
		tmp_b = NULL;
	i = 0;
	while (i < frame->len - 1)
	{
		printf_heads(tmp_a, tmp_b);
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
		i++;
	}
	ft_printf("- -\na b\n");
}

void	printf_heads(t_pi_el *head_a, t_pi_el *head_b)
{
	if (!head_a)
		ft_printf("  %d\n", head_a->value, head_b->value);
	else if (!head_b)
		ft_printf("%d  \n", head_a->value);
	else
		ft_printf("%d %d\n", head_a->value, head_b->value);
}
