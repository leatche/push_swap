/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:52:14 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/20 17:15:20 by tcherepoff       ###   ########.fr       */
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

typedef struct t_stack {
	int				content;
	struct t_stack *prev;
	struct t_stack *next;
}				 t_stack;

static t_stack *ft_create_list(int argc, char **argv);
int			ft_create_element(int nbr, t_stack **new_element);
int			ft_add_new_element(int nbr, t_stack **stack_tmp);
// static int	initialize_stack(t_stack **stack_a, t_stack **stack_b, char **tab);
int			ft_check_duplicate(t_stack *stack_a);
#endif