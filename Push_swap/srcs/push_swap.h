/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:30:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/22 18:47:23 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42lib/libft.h"

# ifndef SIZE_BIT
#  define SIZE_BIT 31
# endif

typedef struct s_pile_elem {
	int					value;
	int					cp_value;
	struct s_pile_elem	*next;
	struct s_pile_elem	*privious;
}	t_pi_el;

// main.c
int		core_push_swap(int len_tab, char **tab_num_ascii);
t_pi_el	*get_pile_a(int len, char **ascii_value);

// push_swap_checking input.c 
int		main_checking_input(char **ascii_num_tab);
int		check_digit_flow(char **asci_num);
int		check_double(char **asci_num);
int		ft_check_int(char *strnum);
int		check_flow(char *num, int len);

//push_swap_piles.c
t_pi_el	*create_element(int val_2_save);
t_pi_el	*add_elem_pile(t_pi_el *privious_elem, int val_2_save);
void	link_last_2_first(t_pi_el *last_elem, t_pi_el *first_elem);
void	free_pile(t_pi_el *privious_elem);
int		remove_elem_pile(t_pi_el **head, t_pi_el *first_elem);

// push_swap_utils.c
char	**ft_cpy_in_new_tab(char **old_tab, int len);
int		exit_message(int i);
void	printf_heads(t_pi_el *head_a, t_pi_el *head_b);
void	printf_piles(t_pi_el *head_a, t_pi_el *head_b, int len);

// push_swap_pile_operation.c
int		swap(t_pi_el *head, char pile);
int		push(t_pi_el **head, t_pi_el *start, t_pi_el **head_e, char p);
int		rotate(t_pi_el **head_pile, t_pi_el *first, char pile);
int		rev_rotate(t_pi_el **head_pile, t_pi_el *first, char pile);

// push_swap_pile_operation_double.c
int		swap_ab(t_pi_el *head_a, t_pi_el *head_b);
int		rotate_ab(t_pi_el **p_a, t_pi_el *heada, t_pi_el **p_b, t_pi_el *headb);
int		rev_rotate_ab(t_pi_el **p_a, t_pi_el *ha, t_pi_el **p_b, t_pi_el *hb);

//push_swap_solve_engine.c
int		radix_sort(t_pi_el *fh_a, t_pi_el *fh_b, int len);
int		check_order(t_pi_el *head, int len);

#endif 
