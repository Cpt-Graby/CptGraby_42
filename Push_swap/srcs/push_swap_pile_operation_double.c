/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_operation_double.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:09:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/27 16:41:05 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_ab(t_pi_f *frame, int print)
{
	swap(frame, 'a', 0);
	swap(frame, 'b', 0);
	if (print)
		ft_printf("ss\n");
	return (1);
}

int	rotate_ab(t_pi_f *frame, int print)
{
	rotate(frame, 'a', 0);
	rotate(frame, 'b', 0);
	if (print)
		ft_printf("rr\n");
	return (1);
}

int	rev_rotate_ab(t_pi_f *frame, int print)
{
	rev_rotate(frame, 'a', 0);
	rev_rotate(frame, 'b', 0);
	if (print)
		ft_printf("rrr\n");
	return (1);
}
