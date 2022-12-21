/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/21 11:20:01 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pi_el	*get_pile_a(int len, char **ascii_value)
{
	int		i;
	int		tmp;
	t_pi_el	*first;
	t_pi_el	*new;

	i = 0;
	tmp = ft_atoi(ascii_value[i]);
	first = create_element(tmp);
	if (!first)
		return (NULL);
	new = first;
	while (++i < len - 1)
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
	radix_sort(lec_head_a, lec_head_b, argc - 1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**new_argv;
	int		new_argc;

	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	else if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		new_argc = ft_lensplit(new_argv);
	}
	else
	{
		new_argc = argc;
		new_argv = ft_cpy_in_new_tab(argv, argc);
	}
	if (!main_checking_input(new_argv))
		return (-1);
	if (core_push_swap(new_argc, new_argv))
		return (exit_message(-1));
	return (0);
}
