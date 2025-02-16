/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:17:01 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:43:00 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_where_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count_top;
	int	count_bottom;

	count_top = ft_count_top_of_top(number_chose, stack_a, stack_b);
	count_bottom = ft_count_bottom_of_top(number_chose, stack_a, stack_b);
	if (count_top <= count_bottom)
		return (count_top);
	else
		return (count_bottom);
}

int	ft_where_bottom(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count_top;
	int	count_bottom;

	count_top = ft_count_top_of_bottom(number_chose, stack_a, stack_b);
	count_bottom = ft_count_bottom_of_bottom(number_chose, stack_a, stack_b);
	if (count_top <= count_bottom)
		return (count_top);
	else
		return (count_bottom);
}

int	ft_top(t_stack *number_chose, t_stack **stack_a, t_stack **stack_b)
{
	int	count_top;
	int	count_bottom;

	count_top = ft_count_top_of_top(number_chose, *stack_a, *stack_b);
	count_bottom = ft_count_bottom_of_top(number_chose, *stack_a, *stack_b);
	if (count_top <= count_bottom)
		return (1);
	else
		return (2);
}

int	ft_bottom(t_stack *number_chose, t_stack **stack_a, t_stack **stack_b)
{
	int	count_top;
	int	count_bottom;

	count_top = ft_count_top_of_bottom(number_chose, *stack_a, *stack_b);
	count_bottom = ft_count_bottom_of_bottom(number_chose, *stack_a, *stack_b);
	if (count_top <= count_bottom)
		return (1);
	else
		return (2);
}
