/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:30:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/14 13:45:24 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42lib/libft.h"

typedef struct s_pile_elem {
	int					value;
	struct s_pile_elem	*next;
	struct s_pile_elem	*privious;
}	t_pile_elem;

// main.c
int			check_pile_order(int *pile, int len);

// push_swap_checking input.c 
int			check_digit_flow(int arg, char **asci_num);
int			check_double(int arg, char **asci_num);
int			ft_check_int(char *strnum);
int			check_flow(char *num, int len);
//push_swap_piles.c
t_pile_elem	*create_element(int val_2_save);
t_pile_elem	*add_elem_pile(t_pile_elem *privious_elem, int val_2_save);
void		link_last_2_first(t_pile_elem *last_elem, t_pile_elem *first_elem);
void		free_pile(t_pile_elem *privious_elem);

// push_swap_utils.c
void		printf_heads(t_pile_elem **head_a, t_pile_elem **head_b);
void		printf_piles(t_pile_elem **head_a, t_pile_elem **head_b, int len);

#endif 
