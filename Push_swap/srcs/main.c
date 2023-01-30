/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/30 08:46:06 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**new_argv;
	int		new_argc;

	if (argc == 1)
		return (0);
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
	if (new_argv[0] != NULL && !main_checking_input(new_argv))
		return (exit_message(-1));
	if (new_argv[0] != NULL && new_argc <= 6 && new_argc > 2)
		hard_code_swap(new_argc, new_argv);
	if (new_argv[0] != NULL && new_argc > 6)
		core_push_swap(new_argc, new_argv);
	ft_free_tab((void **)new_argv, new_argc);
	return (0);
}

int	core_push_swap(int len_tab, char **tab_num_ascii)
{
	t_pi_f	*pile_frame;
	t_pi_f	*pile_frame_2;
	t_pi_el	*lec_head_a;
	t_pi_el	*lec_head_b;
	t_pi_el	*lec_head_c;

	lec_head_a = get_pile_a(len_tab, tab_num_ascii);
	lec_head_c = get_pile_a(len_tab, tab_num_ascii);
	if (!lec_head_a || !lec_head_c)
	{
		if (lec_head_a)
			free_pile(&lec_head_a, len_tab - 1);
		return (-1);
	}
	lec_head_b = NULL;
	pile_frame = set_frame(&lec_head_a, &lec_head_b, len_tab);
	pile_frame_2 = set_frame(&lec_head_c, &lec_head_b, len_tab);
	radix_sort(pile_frame, 0);
	set_index(pile_frame, pile_frame_2);
	free_frame(pile_frame);
	radix_sort(pile_frame_2, 1);
	free_frame(pile_frame_2);
	return (0);
}

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
		{
			free_pile(&first, i);
			return (NULL);
		}
	}
	link_last_2_first(new, first);
	return (first);
}
