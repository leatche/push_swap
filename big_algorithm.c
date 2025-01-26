/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:20:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/26 19:55:43 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		index;


	while (ft_strlen_stack(stack_b) != 2)
		ft_pb(stack_b, stack_a);
	ft_two_number(stack_b);
	while (ft_strlen_stack(stack_a) != 3)
	{
		index = ft_tester_each(stack_a, stack_b);
		
	}
}
int	ft_valid_number(t_stack *tmp, t_stack *stack_a, t_stack *stack_b, int middle)
{
	int	count_stack_b;
	int	indice;

	count_stack_b = ft_strlen_stack(stack_b);
	indice = ft_get_indice(stack_a, tmp);
	if (indice <= middle && indice <= (count_stack_b + 1))
		return (1);
	else if (indice > middle && indice > (ft_strlen_stack(stack_a) - count_stack_b + 1))
		return (2);
	else
		return (-1);
}

int	ft_tester_each(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		count_move;
	int		count_move_new;
	int		good_index;
	
	tmp = stack_a;
	count_move = 100;
	while (count_move = 100 || tmp != stack_a)
	{
		if (ft_valid_number(tmp, stack_a, stack_b, ft_middle(stack_a)) == -1)
			tmp = tmp->next;
		else if (ft_valid_number(tmp, stack_a, stack_b, ft_middle(stack_a)) == 1)
			count_move_new = ft_where_top(tmp, stack_a, stack_b);
		else
			count_move_new = ft_where_bottom(tmp, stack_a, stack_b);
		if (count_move_new < count_move)
		{
			count_move = count_move_new;
			good_index = ft_get_index(tmp, stack_a);
		}	
		tmp = tmp->next;
	}
	return (good_index);
}
