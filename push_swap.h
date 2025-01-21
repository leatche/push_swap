/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:52:14 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/21 02:13:13 by ltcherep         ###   ########.fr       */
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

static t_stack	*ft_create_list(int argc, char **argv);
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

#endif
