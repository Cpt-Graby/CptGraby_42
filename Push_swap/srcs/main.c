/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/16 13:08:30 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
typedef struct s_pile_elem {
	int					value;
	struct s_pile_elem	*next;
	struct s_pile_elem	*privious;
}	t_pi_el;
 */

t_pi_el	*get_pile_a(int len, char **ascii_value)
{
	int		i;
	int		tmp;
	t_pi_el	*first;
	t_pi_el	*new;

	i = 1;
	tmp = ft_atoi(ascii_value[i]);
	first = create_element(tmp);
	if (!first)
		return (NULL);
	new = first;
	while (++i < len)
	{
		tmp = ft_atoi(ascii_value[i]);
		new = add_elem_pile(new, tmp);
		if (!new)
			return (NULL);
	}
	link_last_2_first(new, first);
	return (first);
}

int	core_push_swap(int argc, char **argv)
{
	t_pi_el	*lec_head_a;
	t_pi_el	*lec_head_b;

	lec_head_a = get_pile_a(argc, argv);
	if (!lec_head_a)
		return (-1);
	lec_head_b = NULL;
	printf_piles(lec_head_a, lec_head_b, argc - 1);
	rotate(&lec_head_a, lec_head_a, 'a');
	printf_piles(lec_head_a, lec_head_b, argc - 1);
	push(&lec_head_a, lec_head_a, &lec_head_b, 'b');
	printf_piles(lec_head_a, lec_head_b, argc - 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error \n", 2);
		return (-1);
	}
	else
	{
		if (!check_digit_flow(argc, argv))
			return (-1);
		if (!check_double(argc, argv))
			return (-1);
		if (core_push_swap(argc, argv))
		{
			ft_putstr_fd("Error \n", 2);
			return (-1);
		}
		return (0);
	}
}
