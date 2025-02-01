/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/01 15:34:24 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_list(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	stack_a = ft_executate(stack_a, stack_b);
	if (ft_sorted_a(stack_a) == -1)
	{
		write(2, "la chaine n'est pas trié\n", 27);
		return (-1);
	}
	free(stack_b);
	ft_free_pile(stack_a);
	return (0);
}

t_stack *ft_executate(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strlen_stack(stack_a) == 1 || ft_strlen_stack(stack_a) == 0)
		return (stack_a);
	else if (ft_strlen_stack(stack_a) == 2)
		ft_two_number(stack_a);
	else if (ft_strlen_stack(stack_a) == 3)
		ft_three_number(stack_a);
	else if (ft_strlen_stack(stack_a) == 4 || ft_strlen_stack(stack_a) == 5)
		ft_five_number(stack_a, stack_b);
	else
		ft_big_algorithm(stack_a, stack_b);
	return (stack_a);
}


int	ft_where_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count_top;
	int count_bottom;

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
	int count_bottom;

	count_top = ft_count_top_of_bottom(number_chose, stack_a, stack_b);
	count_bottom = ft_count_bottom_of_bottom(number_chose, stack_a, stack_b);
	if (count_top <= count_bottom)
		return (count_top);
	else
		return (count_bottom);
}

///////////////////////////////////tous les types de count /////////////////////////////////////////////////////////

int	ft_count_top_of_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;
	int	win;

	count = ft_search_less(number_chose, stack_b);
	index = ft_get_index(number_chose, stack_a) - 1;
	win = 0;
	while (count - win > 0 && index - win > 0)
			win++;
	count_move = (count + index) - win + 1;
	return (count_move);
}

int	ft_count_bottom_of_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;

	count = ft_strlen_stack(stack_b) - ft_search_less(number_chose, stack_b) + 1;
	index = ft_get_index(number_chose, stack_a) - 1;
	count_move = (count + index) + 1;
	return (count_move);
}


int	ft_count_top_of_bottom(int number_chose, t_stack* stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;

	count = ft_search_less(number_chose, stack_b);
	index = ft_strlen_stack(stack_a) - ft_get_index(number_chose, stack_a);
	count_move = (count + index) + 1;
	return (count_move);
}

int	ft_count_bottom_of_bottom(int number_chose, t_stack* stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;
	int	win;

	count = ft_strlen_stack(stack_b) - ft_search_less(number_chose, stack_b);
	index = ft_strlen_stack(stack_a) - ft_get_index(number_chose, stack_a);
	win = 0;
	while (count - win != 0 && index - win != 0)
		win++;
	count_move = (count + index) - win + 1;
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

	tmp = stack_b->next;
	count = 0;
	if (is_maximum(number_chose, stack_b) == 1)
		return (count);
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

}
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

int	ft_sorted_a(t_stack *stack_a)
{
	
}