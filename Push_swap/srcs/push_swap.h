/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:30:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/09 18:09:34 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42lib/libft.h"
// main.c
int	check_pile_order(int *pile, int len);

// push_swap_checking input.c 
int	ckeck_digit_flow(int arg, char **asci_num);
int	check_double(int arg, char **asci_num);
int	ft_check_int(char *strnum);
int	check_flow(char *num, int len);

// push_swap_utils.c

#endif 
