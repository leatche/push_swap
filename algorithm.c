/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/01/27 04:39:54 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

//////////////////////////////////////NEXT TIME∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕/////////
/*
- mon algo pour 5 peut faire 13 coups
*/

t_stack *ft_push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_list(argc, argv);
	stack_b = NULL;
	if (ft_strlen_stack(stack_a) == 1)
		return (stack_a);
	else if (ft_strlen_stack(stack_a) == 2)
		stack_a = ft_two_number(stack_a);
	else if (ft_strlen_stack(stack_a) == 3)
		ft_three_number(stack_a, stack_b);
	else if (ft_strlen_stack(stack_a) == 4 || ft_strlen_stack(stack_a) == 5)
		ft_five_number(stack_a, stack_b);
	else
		ft_big_algorithm(stack_a, stack_b);
	return (stack_a);
}


int	ft_where_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;
	int	win;

	count = ft_search_less(number_chose, stack_b);
	index = ft_get_index(number_chose, stack_a) - 1;
	win = 0;
	if (count == 1 && index == 0)
		return (1);
	else if (is_minimum(number_chose, stack_b) == 1 && index == 0)
		return (2);
	else if (index == 0)
		count_move = count * 2 + 1;
	else if (count == ft_strlen_stack(stack_b) - 1)
		return (5);
	else
	{
		while (count-- != 0 || index-- != 0)
			win++;
		count_move = (count + index) - win + 1 + count;
	}
	return (count_move);
}

int	ft_where_bottom(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;
	int	win;

	count = ft_strlen_stack(stack_b) - ft_search_less(number_chose, stack_b);
	index = ft_strlen_stack(stack_a) - ft_get_index(number_chose, stack_a) - 1;
	win = 0;
	if (count == 2 && index == ft_strlen_stack(stack_a))
		return (3);
	else if (is_maximum(number_chose, stack_b) == 1 && index == ft_strlen_stack(stack_a))
		return (2);
	else if (index == ft_strlen_stack(stack_a) && count == ft_strlen_stack(stack_b) + 1)
		return (3);
	else
	{
		while (count-- != 0 || index-- != 0)
			win++;
		count_move = (count + index) - win + 1 + count;
	}
	return (count_move);
}

/////////UTILS∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕/

int	ft_strlen_stack(t_stack *stack)
{
	int	i;
	t_stack	*tmp;

	i = 1;
	tmp = stack;
	while (tmp && tmp != stack)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}



int	ft_middle(t_stack *stack)
{
	t_stack *tmp;
	int	count;

	tmp = stack->next;
	count = 1;
	while (tmp && tmp != stack)
	{
		tmp = tmp->next;
		count++;
	}
	count /= 2;
	return (count);
}

int ft_search_less(t_stack *number_chose, t_stack *stack_b)
{
	t_stack	*tmp;
	int		count;

	tmp = stack_b->next;/*
int ft_search_more(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		count;

	tmp = stack_a->prev->prev;
	count = ft_strlen_stack(stack_a) - 1;
	if (is_maximum(stack_b, stack_a) == 1)
		return (ft_strlen_stack(stack_a) + 1);
	else
		while (tmp && tmp != stack_a->prev && tmp->content > stack_b->content)
		{
			tmp = tmp->prev;
			count--;
		}
	return (count);
}
*/
	else
		while (tmp && tmp != stack_b && tmp->content > number_chose->content)
		{
			tmp = tmp->next;
			count++;
		}
	return (count);
}
int	is_minimum(t_stack *actual_number, t_stack	*where)
{

}/*
int ft_search_more(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		count;

	tmp = stack_a->prev->prev;
	count = ft_strlen_stack(stack_a) - 1;
	if (is_maximum(stack_b, stack_a) == 1)
		return (ft_strlen_stack(stack_a) + 1);
	else
		while (tmp && tmp != stack_a->prev && tmp->content > stack_b->content)
		{
			tmp = tmp->prev;
			count--;
		}
	return (count);
}
*/
int	is_maximum(t_stack *actual_number, t_stack	*where)
{

}

int	get_minimum(t_stack *actual_number, t_stack	*where)
{

}

int get_maximum(t_stack *actual_number, t_stack	*where)
{

}


int	ft_get_index(t_stack *tmp, t_stack *stack_a)
{
	int		count;
	t_stack	*tmp_search;

	count = 1;
	tmp_search = stack_a;
	while (tmp_search && tmp_search != tmp)
	{
		tmp_search = tmp_search->next;
		count++;
	}
	return (count);
}

int	ft_repeat_it()

	if (count == 0)
	{

		ft_pb(stack_b, stack_a);

	else if (is_minimum(stack_a, stack_b) == 1)
	{
		ft_pb(stack_b, stack_a);
		ft_rrb(stack_b);
	}
