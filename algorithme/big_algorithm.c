/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:20:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/05 03:05:36 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	while (ft_strlen_stack(*stack_b) != 2)
	{
		ft_pb(stack_a, stack_b);
	}
	ft_two_number_b(stack_b);
	while (ft_strlen_stack(*stack_a) != 0)
	{
		index = ft_tester_each(*stack_a, *stack_b);
		printf("i : %d\n", index);
		ft_now_push_it(index, stack_a, stack_b);
	}
	// ft_three_number(stack_a);
//	if (ft_sorted_b(*stack_b) == -1)
	//	ft_put_it_back(stack_b);
	while (ft_strlen_stack(*stack_b) > 0)
		ft_pa(stack_a, stack_b); /// faux il faut bien le placer pour les 3 de stack_a
}

int	ft_valid_number(t_stack *tmp, t_stack *stack_a, t_stack *stack_b,
	int middle)
{
	int	count_stack_b;
	int	indice;

	count_stack_b = ft_strlen_stack(stack_b);
	indice = ft_get_index(stack_a, tmp);
	if (indice <= middle && indice <= (count_stack_b + 1))
		return (1);
	else if (indice > middle && indice > (ft_strlen_stack(stack_a)
			- count_stack_b + 1))
		return (2);
	else
		return (-1);
	return (-1);
}

int	ft_tester_each(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		count_move;
	int		count_move_new;
	int		good_index;
	int		isvalid;

	tmp = stack_a;
	count_move = INT_MAX;
	while (count_move == INT_MAX || tmp != stack_a)
	{
		isvalid = ft_valid_number(tmp, stack_a, stack_b, ft_middle(stack_a));
		if (isvalid == 1)
			count_move_new = ft_where_top(tmp, stack_a, stack_b);
		else if (isvalid == 2)
			count_move_new = ft_where_bottom(tmp, stack_a, stack_b);
		if (count_move_new < count_move)
		{
			count_move = count_move_new;
			good_index = ft_get_index(tmp, stack_a) - 1;
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

///////////// ft  place/////////////////////////////////////////////////////

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

/////////////////// UTILS A PLACE //////////////////////////////////////////
void	ft_special_top_top(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index;
	int	win;

	count = ft_search_less_b(tmp, stack_b);
	index = ft_get_index(tmp, *stack_a) - 1;
	win = 0;
	printf("ft_special_top_top %d %d\n", count, index);
	while (count-- > 0 && index-- > 0)
		win++;
	while (win-- > 0)
		ft_rr(stack_a, stack_b);
	while (count-- > 0)
		ft_rb(stack_b);
	while (index-- > 0)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
}

void	ft_special_top_bottom(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index;

	printf("ft_special_top_bottom\n");
	count = ft_strlen_stack(*stack_b) - ft_search_less_b(tmp, stack_b) + 1;
	index = ft_get_index(tmp, *stack_a) - 1;
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

	printf("ft_special_bottom_top\n");
	count = ft_search_less_b(tmp, stack_b);
	index = ft_strlen_stack(*stack_a) - ft_get_index(tmp, *stack_a);
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
	int	win;

	printf("ft_special_bottom_bottom\n");
	count = ft_strlen_stack(*stack_b) - ft_search_less_b(tmp, stack_b) + 1;
	index = ft_strlen_stack(*stack_a) - ft_get_index(tmp, *stack_a) + 1;
	win = 0;
	while (count-- > 0 && index-- > 0)
		win++;
	while (win-- > 0)
		ft_rrr(stack_a, stack_b);
	while (count-- > 0)
		ft_rrb(stack_b);
	while (index-- > 0)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
}
///////////////////////////////// UTILS ////////////////////////////////////

int	ft_sorted_b(t_stack **stack_b)
{
	int	i;
	int	length;
	t_stack	*tmp;

	tmp = *stack_b;
	length = ft_strlen_stack(*stack_b);
	if (length > 0)
	{
		i = 1;
		while (tmp && i++ < length)
		{
			if (tmp->content < tmp->next->content)
				return (-1);
			tmp = tmp->next;
		}
		return (1);
	}
	return (1);
}
/*
void	ft_put_it_back(t_stack **stack_b)
{
	t_stack	*min;
	int		index_min;

//	min = ft_min(stack_b);
	//index_min = ft_get_index(min, *stack_b);
	if (index_min > ft_middle(*stack_b))
	{
		while (ft_get_index(min, *stack_b) != ft_strlen_stack(*stack_b))
			ft_rb(stack_b);
	}
	else
	{
		while (ft_get_index(min, *stack_b) != ft_strlen_stack(*stack_b))
			ft_rrb(stack_b);
	}
}*/
/*
t_stack	*ft_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = stack->next;
	max->content = stack->content;
	while (tmp != stack)
	{
		if (tmp->content > max->content)
			max->content = tmp->content;
		tmp = tmp->next;
	}
	if (tmp->content > max->content)
		max->content = tmp->content;
	return (max);
}*/