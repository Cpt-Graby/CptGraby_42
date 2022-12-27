/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 20:31:01 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (exit_message(-1));
	core_push_swap(new_argc, new_argv);
	return (0);
}

int	get_index(t_pi_f *frame, int target_value)
{
	int		count;
	t_pi_el	*tmp;

	count = 0;
	tmp = frame->f_elem_a;
	while (tmp->value != target_value)
	{
		count++;
		tmp = tmp->next;
	}
	ft_printf("%d", count);
	return (count);
}

void	set_index(t_pi_f *frame, t_pi_f *frame2)
{
	int		i;

	i = 0;
	while (i < frame2->len - 2)
	{
		frame2->f_elem_a->index = get_index(frame, frame2->f_elem_a->value);
		rotate(frame2, 'a', 0);
		i++;
	}
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
	if (!lec_head_a)
		return (-1);
	lec_head_b = NULL;
	pile_frame = set_frame(&lec_head_a, &lec_head_b, len_tab);
	pile_frame_2 = set_frame(&lec_head_c, &lec_head_b, len_tab);
	radix_sort(pile_frame, 0);
	set_index(pile_frame, pile_frame_2);
	printf_piles(pile_frame_2);
	radix_sort(pile_frame_2, 1);
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
			return (NULL);
	}
	link_last_2_first(new, first);
	return (first);
}
