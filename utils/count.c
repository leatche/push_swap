/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:19:23 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:22:35 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_top_of_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	index;
	int	win;
	int count_move;

	count = ft_search_less_b(number_chose, &stack_b);
	index = ft_get_index(number_chose->content, stack_a) - 1;
	index = index % ft_strlen_stack(stack_a);
	count = count % ft_strlen_stack(stack_b);
	win = 0;
	while (count - win > 0 && index - win > 0)
		win++;
	count_move = (count + index) - win;
	return (count_move);
}

int	ft_count_bottom_of_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;

	count = ft_strlen_stack(stack_b) - ft_search_less_b(number_chose, &stack_b);
	index = ft_get_index(number_chose->content, stack_a) - 1;
	index = index % ft_strlen_stack(stack_a);
	count = count % ft_strlen_stack(stack_b);
	count_move = (count + index);
	return (count_move);
}

int	ft_count_top_of_bottom(t_stack *number_chose, t_stack* stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;

	count = ft_search_less_b(number_chose, &stack_b);
	index = ft_strlen_stack(stack_a) - ft_get_index(number_chose->content, stack_a) + 1;
	index = index % ft_strlen_stack(stack_a);
	count = count % ft_strlen_stack(stack_b);
	count_move = (count + index);
	return (count_move);
}

int	ft_count_bottom_of_bottom(t_stack *number_chose, t_stack* stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;
	int	win;
	
	count = ft_strlen_stack(stack_b) - ft_search_less_b(number_chose, &stack_b);
	index = ft_strlen_stack(stack_a) - ft_get_index(number_chose->content, stack_a) + 1;
	index = index % ft_strlen_stack(stack_a);
	count = count % ft_strlen_stack(stack_b);
	win = 0;
	while (count - win > 0 && index - win > 0)
		win++;
	count_move = (count + index) - win;
	return (count_move);
}
