/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:29:26 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:30:32 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_special_top_top(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index;

	count = ft_search_less_b(tmp, stack_b);
	index = ft_get_index(tmp->content, *stack_a) - 1;
	index = index % ft_strlen_stack(*stack_a);
	count = count % ft_strlen_stack(*stack_b);
	while (count > 0 || index > 0)
	{
		if (count > 0 && index > 0)
			ft_rr(stack_a, stack_b);
		else if (count > 0)
			ft_rb(stack_b);
		else if (index > 0)
			ft_ra(stack_a);
		count--;
		index--;
	}
	ft_pb(stack_a, stack_b);
}

void	ft_special_top_bottom(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index;

	count = ft_strlen_stack(*stack_b) - ft_search_less_b(tmp, stack_b);
	index = ft_get_index(tmp->content, *stack_a) - 1;
	index = index % ft_strlen_stack(*stack_a);
	count = count % ft_strlen_stack(*stack_b);
	while (count-- > 0)
		ft_rrb(stack_b);
	while (index-- > 0)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
}

void	ft_special_bottom_top(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index;
	
	count = ft_search_less_b(tmp, stack_b);
	index = ft_strlen_stack(*stack_a) - ft_get_index(tmp->content, *stack_a) + 1;
	index = index % ft_strlen_stack(*stack_a);
	count = count % ft_strlen_stack(*stack_b);
	while (count-- > 0)
		ft_rb(stack_b);
	while (index-- > 0)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
}

void	ft_special_bottom_bottom(t_stack *tmp, t_stack **stack_a,
		t_stack **stack_b)
{
	int	count;
	int	index;

	count = ft_strlen_stack(*stack_b) - ft_search_less_b(tmp, stack_b);
	index = ft_strlen_stack(*stack_a) - ft_get_index(tmp->content, *stack_a) + 1;
	index = index % ft_strlen_stack(*stack_a);
	count = count % ft_strlen_stack(*stack_b);
	while (count > 0 || index > 0)
	{
		if (count > 0 && index > 0)
			ft_rrr(stack_a, stack_b);
		else if (count > 0)
			ft_rrb(stack_b);
		else if (index > 0)
			ft_rra(stack_a);
		count--;
		index--;
	}
	ft_pb(stack_a, stack_b);
}
