/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:20:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:32:21 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	while (ft_strlen_stack(*stack_b) != 2)
		ft_pb(stack_a, stack_b);
	ft_two_number_b(stack_b);
	while (ft_strlen_stack(*stack_a) != 0)
	{
		index = ft_tester_each(stack_a, stack_b);
		ft_now_push_it(index, stack_a, stack_b);
	}
	if (ft_sorted_b(stack_b) == -1)
		ft_put_it_back(stack_b);
	while (ft_strlen_stack(*stack_b) > 0)
		ft_pa(stack_a, stack_b);
}

int	ft_tester_each(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		count_move;
	int		count_move_new;
	int		good_index;
	int		isvalid;

	tmp = *stack_a;
	count_move = INT_MAX;
	while (count_move == INT_MAX || tmp != *stack_a)
	{
		isvalid = ft_valid_number(tmp, *stack_a, *stack_b, ft_middle(*stack_a));
		if (isvalid == 1)
			count_move_new = ft_where_top(tmp, *stack_a, *stack_b);
		else
			count_move_new = ft_where_bottom(tmp, *stack_a, *stack_b);
		if (count_move_new < count_move)
		{
			count_move = count_move_new;
			good_index = ft_get_index(tmp->content, *stack_a) - 1;
		}
		tmp = tmp->next;
	}
	return (good_index);
}

void	ft_now_push_it(int index, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (index > 0)
	{
		tmp = tmp->next;
		index--;
	}
	ft_place(tmp, stack_a, stack_b, ft_middle(*stack_a));
}

void	ft_place(t_stack *tmp, t_stack **stack_a, t_stack **stack_b, int middle)
{
	if (ft_valid_number(tmp, *stack_a, *stack_b, middle) == 1)
	{
		if (ft_top(tmp, stack_a, stack_b) == 1)
			ft_special_top_top(tmp, stack_a, stack_b);
		else
			ft_special_top_bottom(tmp, stack_a, stack_b);
	}
	else
	{
		if (ft_bottom(tmp, stack_a, stack_b) == 1)
			ft_special_bottom_top(tmp, stack_a, stack_b);
		else
			ft_special_bottom_bottom(tmp, stack_a, stack_b);
	}
}

void	ft_put_it_back(t_stack **stack_b)
{
	int		index_min;
	
	index_min = ft_min(stack_b);
	if (index_min < ft_middle(*stack_b))
	{
		while (ft_min(stack_b) != ft_strlen_stack(*stack_b))
			ft_rb(stack_b);
	}
	else
	{
		while (ft_min(stack_b) != ft_strlen_stack(*stack_b))
			ft_rrb(stack_b);
	}
}
