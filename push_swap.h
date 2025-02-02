/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:52:14 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/02 01:57:43 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// typedef struct s_tac
// {
// 	t_stack		*begin;
// }				t_tac;

void			ft_pa(t_stack **stack_a, t_stack **stack_b);
void			ft_pb(t_stack **stack_a, t_stack **stack_b);
void			ft_r(t_stack **stack);
void			ft_ra(t_stack **stack_a);
void			ft_rb(t_stack **stack_b);
void			ft_rr(t_stack **stack_a, t_stack **stack_b);
void			ft_rrx(t_stack **stack);
void			ft_rra(t_stack **stack_a);
void			ft_rrb(t_stack **stack_b);
void			ft_rrr(t_stack **stack_a, t_stack **stack_b);
void			ft_s(t_stack **stack);
void			ft_sa(t_stack **stack_a);
void			ft_sb(t_stack **stack_b);
void			ft_ss(t_stack **stack_a, t_stack **stack_b);

t_stack			*ft_create_list(int argc, char **argv);
int				ft_create_element(int nbr, t_stack **new_element);
int				ft_add_new_element(int nbr, t_stack **stack_tmp);
void			free_stack(t_stack *stack);

void			ft_error(void);
void			ft_letter(char **argv);
int				ft_check_bad_position(char **argv, int i, int j);
int				ft_check_letter_bad_position(char **argv);
int				ft_check_duplicate(t_stack *stack_a);

int				sign(int c);
int				digit(int c);
int				space(int c);

void			ft_big_algorithm(t_stack **stack_a, t_stack **stack_b);
int				ft_valid_number(t_stack *tmp, t_stack *stack_a,
					t_stack *stack_b, int middle);
int				ft_tester_each(t_stack *stack_a, t_stack *stack_b);
void			ft_now_push_it(int index, t_stack **stack_a, t_stack **stack_b);
void			ft_place(t_stack *tmp, t_stack **stack_a, t_stack **stack_b,
					int middle);
int				ft_top(t_stack *number_chose, t_stack **stack_a,
					t_stack **stack_b);
int				ft_bottom(t_stack *number_chose, t_stack **stack_a,
					t_stack **stack_b);
void			ft_special_top_top(t_stack *tmp, t_stack **stack_a,
					t_stack **stack_b);
void			ft_special_top_bottom(t_stack *tmp, t_stack **stack_a,
					t_stack **stack_b);
void			ft_special_bottom_top(t_stack *tmp, t_stack **stack_a,
					t_stack **stack_b);
void			ft_special_bottom_bottom(t_stack *tmp, t_stack **stack_a,
					t_stack **stack_b);
int				ft_sorted_b(t_stack *stack_b);
void			ft_put_it_back(t_stack **stack_b);

void			ft_two_number(t_stack **stack_a);
void			ft_three_number(t_stack **stack_a);
void			ft_four_number(t_stack **stack_a, t_stack **stack_b);
void			ft_five_number(t_stack **stack_a, t_stack **stack_b);
t_stack			*ft_min(t_stack *stack_a);
t_stack			*ft_little(t_stack *stack_a, t_stack *min);

void			ft_executate(t_stack **stack_a, t_stack **stack_b);
int				ft_where_top(t_stack *number_chose, t_stack *stack_a,
					t_stack *stack_b);
int				ft_where_bottom(t_stack *number_chose, t_stack *stack_a,
					t_stack *stack_b);
int				ft_count_top_of_top(t_stack *number_chose, t_stack *stack_a,
					t_stack *stack_b);
int				ft_count_bottom_of_top(t_stack *number_chose, t_stack *stack_a,
					t_stack *stack_b);
int				ft_count_top_of_bottom(t_stack *number_chose, t_stack *stack_a,
					t_stack *stack_b);
int				ft_count_bottom_of_bottom(t_stack *number_chose, t_stack *stack_a,
					t_stack *stack_b);
int				ft_strlen_stack(t_stack *stack);
int				ft_middle(t_stack *stack);
int				ft_search_less(t_stack *number_chose, t_stack *stack_b);
int				is_minimum(t_stack *actual_number, t_stack	*where);
int				is_maximum(t_stack *actual_number, t_stack	*where);
int				ft_get_index(t_stack *tmp, t_stack *stack_a);

t_stack			*ft_stacklast(t_stack *lst);
void			print_stack(t_stack *stack);
int				ft_sorted_a(t_stack *stack_a);

#endif