/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:30:18 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/26 17:33:47 by agonelle         ###   ########.fr       */
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
	int					index;
	struct s_pile_elem	*next;
	struct s_pile_elem	*privious;
}	t_pi_el;

typedef struct s_pile_frame {
	int					len;
	struct s_pile_elem	**head_a;
	struct s_pile_elem	*f_elem_a;
	int					len_pile_a;
	struct s_pile_elem	**head_b;
	struct s_pile_elem	*f_elem_b;
	int					len_pile_b;
}	t_pi_f;

// main.c
int		core_push_swap(int len_tab, char **tab_num_ascii);
t_pi_el	*get_pile_a(int len, char **ascii_value);
void	printf_frame(t_pi_f *pile_frame, char *s);

// push_swap_checking input.c 
int		main_checking_input(char **ascii_num_tab);
int		check_digit_flow(char **asci_num);
int		check_double(char **asci_num);
int		ft_check_int(char *strnum);
int		check_flow(char *num, int len);

//push_swap_sol_5_3.c
int		print_and_return(char *msg, int ret_val);
int		sort_2_element(t_pi_f *frame);
int		sort_3_element(t_pi_f *frame);
int		hard_code_swap(int len_tab, char **tab_num_ascii);

//push_swap_sol_5_3.c
int		sort_5_element(t_pi_f *pile_frame, char **tab, int len);
int		sort_4_element(t_pi_f *pile_frame, char **tab, int len);

//push_swap_piles.c
t_pi_el	*create_element(int val_2_save);
t_pi_el	*add_elem_pile(t_pi_el *privious_elem, int val_2_save);
void	link_last_2_first(t_pi_el *last_elem, t_pi_el *first_elem);
int		remove_elem_pile(t_pi_el **head, t_pi_el *first_elem);
void	insert_elem_pile(t_pi_el *element, t_pi_el **head);

//push_swap_piles2.c
void	set_index(t_pi_f *frame, t_pi_f *frame2);
int		get_index(t_pi_f *frame, int target_value);
void	free_pile(t_pi_el **adress_elem, int len2del);

//push_swap_piles_frames.c
t_pi_f	*set_frame(t_pi_el **lec_a, t_pi_el **lec_b, int max_len);
void	actu_frame(t_pi_f *frame, t_pi_el **lec_a, t_pi_el **lec_b);
void	free_frame(t_pi_f *frame);

//push_swap_utils.c
char	**ft_cpy_in_new_tab(char **old_tab, int len);
int		exit_message(int i);
void	printf_heads(t_pi_el *head_a, t_pi_el *head_b);
void	printf_piles(t_pi_f *frame);
void	printf_index(t_pi_f *frame);

// push_swap_pile_operation.c
int		swap(t_pi_f *frame, char pile, int print);
int		push(t_pi_f *frame, char pile, int print);
int		rotate(t_pi_f *frame, char pile, int print);
int		rev_rotate(t_pi_f *frame, char pile, int print);

// push_swap_pile_operation_double.c
int		swap_ab(t_pi_f *frame, int print);
int		rotate_ab(t_pi_f *frame, int print);
int		rev_rotate_ab(t_pi_f *frame, int print);

//push_swap_solve_engine.c
void	sort_bits(t_pi_f *frame, int index, int print);
int		radix_sort(t_pi_f *frame, int print);
int		check_order_value(t_pi_el *head, int len);
int		check_order_index(t_pi_el *head, int len);

#endif 
