/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 17:10:43 by agonelle         ###   ########.fr       */
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

void	printf_frame(t_pi_f *pile_frame, char *s)
{
	ft_printf("start %s\n", s);
	ft_printf("pile_head_a: %p\n", *pile_frame->head_a);
	ft_printf("lec_head_a : %p\n", pile_frame->f_elem_a);
	ft_printf("pile_head_b: %p\n", *pile_frame->head_b);
	ft_printf("lec_head_b : %p\n", pile_frame->f_elem_b);
	ft_printf("end %s\n", s);
}

int	core_push_swap(int len_tab, char **tab_num_ascii)
{
	t_pi_f	*pile_frame;
	t_pi_el	*lec_head_a;
	t_pi_el	*lec_head_b;

	lec_head_a = get_pile_a(len_tab, tab_num_ascii);
	if (!lec_head_a)
		return (-1);
	lec_head_b = NULL;
	pile_frame = set_frame(&lec_head_a, &lec_head_b, len_tab);
	radix_sort(pile_frame);
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
