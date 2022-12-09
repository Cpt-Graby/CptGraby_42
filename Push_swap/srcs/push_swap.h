/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:30:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/09 11:49:49 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42lib/libft.h"
// main.c
int	ckeck_digit_flow(int arg, char **asci_num);
int	check_double(int arg, char **asci_num);

// push_swap_utils.c
int	ft_check_int(char *strnum);
int	check_flow(char *num, int len);

#endif 
