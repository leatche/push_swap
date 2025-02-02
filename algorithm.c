/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/02 22:52:03 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
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
	ft_executate(&stack_a, &stack_b);
//	print_stack(stack_a);
	//if (ft_sorted_a(stack_a) == -1)
	//{
		//write(2, "la chaine n'est pas trié\n", 27);
	//	return (-1);
	//}
	free(stack_b);
	free_stack(stack_a);
	return (0);
}

void ft_executate(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strlen_stack(*stack_a) == 1 || ft_strlen_stack(*stack_a) == 0)
		return ;
	else if (ft_strlen_stack(*stack_a) == 2)
		ft_two_number(stack_a);
	else if (ft_strlen_stack(*stack_a) == 3)
		ft_three_number(stack_a);
	else if (ft_strlen_stack(*stack_a) == 4)
		ft_four_number(stack_a, stack_b);
	else if (ft_strlen_stack(*stack_a) == 5)
		ft_five_number(stack_a, stack_b);
	else
		ft_big_algorithm(stack_a, stack_b);
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


int	ft_count_top_of_bottom(t_stack *number_chose, t_stack* stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;

	count = ft_search_less(number_chose, stack_b);
	index = ft_strlen_stack(stack_a) - ft_get_index(number_chose, stack_a);
	count_move = (count + index) + 1;
	return (count_move);
}

int	ft_count_bottom_of_bottom(t_stack *number_chose, t_stack* stack_a, t_stack *stack_b)
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

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (i == 0 || (tmp && tmp != stack))
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
	t_stack	*tmp;
	int		count;
	int		diff;

	count = actual_number->content;
	tmp = where->prev;
	while (tmp && tmp != where)
	{
		diff = tmp->content;
		if (diff < count)
			return (-1);
		tmp = tmp->prev;
	}
	diff = tmp->content;
	if (diff < count)
		return (-1);
	return (1);
}

int	is_maximum(t_stack *actual_number, t_stack	*where)
{
	t_stack	*tmp;
	int		count;
	int		diff;

	count = actual_number->content;
	tmp = where;
	while (tmp && tmp != where->prev)
	{
		diff = tmp->content;
		if (diff > count)
			return (-1);
		tmp = tmp->next;
	}
	diff = tmp->content;
	if (diff > count)
		return (-1);
	return (1);
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
	(void)stack_a;
	return (0);
}

void print_stack(t_stack *stack)
{
	t_stack *begin;
	int		i;

	i = 0;
	begin = stack;
	while (i == 0 || stack != begin)
	{
		printf("%d ", stack->content);
		i++;
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}