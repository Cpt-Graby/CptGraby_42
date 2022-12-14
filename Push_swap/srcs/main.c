/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/14 14:02:55 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
typedef struct s_pile_elem {
	int					value;
	struct s_pile_elem	*next;
	struct s_pile_elem	*privious;
}	t_pile_elem;
 */

t_pile_elem	**get_pile_a(int len, char **ascii_value)
{
	int			i;
	int			tmp;
	t_pile_elem	**addr_first_elem;
	t_pile_elem	*new;

	i = 1;
	tmp = ft_atoi(ascii_value[i]);
	new = create_element(tmp);
	if (!new)
		return (NULL);
	addr_first_elem = &new;
	while (++i < len)
	{
		tmp = ft_atoi(ascii_value[i]);
		new = add_elem_pile(new, tmp);
		if (!new)
			return (NULL);
	}
	link_last_2_first(new, *addr_first_elem);
	return (addr_first_elem);
}

int	core_push_swap(int argc, char **argv)
{
	t_pile_elem	**lec_head_a;
	t_pile_elem	**lec_head_b;

	lec_head_a = get_pile_a(argc, argv);
	if (!lec_head_a)
		return (-1);
	lec_head_b = NULL;
	printf_piles(lec_head_a, lec_head_b, argc - 1);
	printf("you got at the end \n");
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
