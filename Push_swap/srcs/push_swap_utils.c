/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:29:23 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/22 18:40:11 by agonelle         ###   ########.fr       */
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
	tab[i] = NULL;
	return (tab);
}

int	exit_message(int i)
{
	ft_putstr_fd("Error\n", 2);
	exit (i);
}

void	printf_piles(t_pi_el *head_a, t_pi_el *head_b, int len)
{
	int		i;
	t_pi_el	*tmp_a;
	t_pi_el	*tmp_b;

	if (head_a)
		tmp_a = head_a;
	else
		tmp_a = NULL;
	if (head_b)
		tmp_b = head_b;
	else
		tmp_b = NULL;
	i = 0;
	while (i < len - 1)
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
