/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_operation_double.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:09:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/16 13:46:33 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_ab(t_pi_el *head_a, t_pi_el *head_b)
{
	swap(head_a, 'x');
	swap(head_b, 'x');
	ft_printf("ss\n");
	return (1);
}

int	rotate_ab(t_pi_el **p_a, t_pi_el *heada, t_pi_el **p_b, t_pi_el *headb)
{
	rotate(p_a, heada, 'x');
	rotate(p_b, headb, 'x');
	ft_printf("rr\n");
	return (1);
}

int	rev_rotate_ab(t_pi_el **p_a, t_pi_el *ha, t_pi_el **p_b, t_pi_el *hb)
{
	rev_rotate(p_a, ha, 'x');
	rev_rotate(p_b, hb, 'x');
	ft_printf("rrr\n");
	return (1);
}
