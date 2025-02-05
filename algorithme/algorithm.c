/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/05 04:35:19 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


// mon algo de search less est faux dans le cas :
/*
	3			4	car 3 est plus grand jusqu'a 3 donc le push mais quand on 
					rotate c'est a l'envers
	8
	7
	5
*/

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
	if (ft_check_letter_bad_position(argv) == -1)
	{
		printf("Error: de caractere.\n");
		free_stack(stack_a);
		return (0);
	}
	else if (ft_check_duplicate(stack_a) == 0)
	{
		printf("Error: duplicat.\n");
		free_stack(stack_a);
		return (0);
	}
	else
	{
		printf("la chaine est donc : \n");
		print_stack(stack_a);
	}
	if (ft_sorted_a(&stack_a) == -1)
		ft_executate(&stack_a, &stack_b);
	free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}

void ft_executate(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strlen_stack(*stack_a) == 1 || ft_strlen_stack(*stack_a) == 0)
		return ;
	else if (ft_strlen_stack(*stack_a) == 2)
		ft_two_number_a(stack_a);
	else if (ft_strlen_stack(*stack_a) == 3)
		ft_three_number(stack_a);
	else if (ft_strlen_stack(*stack_a) == 5 || ft_strlen_stack(*stack_a) == 4)
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

	count = ft_search_less_b(number_chose, &stack_b);
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

	count = ft_strlen_stack(stack_b) - ft_search_less_b(number_chose, &stack_b) + 1;
	index = ft_get_index(number_chose, stack_a) - 1;
	count_move = (count + index) + 1;
	return (count_move);
}


int	ft_count_top_of_bottom(t_stack *number_chose, t_stack* stack_a, t_stack *stack_b)
{
	int	count;
	int count_move;
	int	index;

	count = ft_search_less_b(number_chose, &stack_b);
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

	count = ft_strlen_stack(stack_b) - ft_search_less_b(number_chose, &stack_b);
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

int ft_search_less_b(t_stack *number_chose, t_stack **stack_b)
{
	t_stack	*tmp;
	int		count;

	if (!stack_b || !*stack_b)
		return (-1);
	tmp = (*stack_b)->next;
	count = 1;
	if (ft_sorted_b(stack_b) == 1)
	{
		if (is_maximum(number_chose, *stack_b) == 1)
			return (count);
		else 
			while (tmp && tmp != *stack_b && tmp->content > number_chose->content)
			{
				tmp = tmp->next;
				count++;
			}
	}
	else
		count = ft_brave(stack_b, number_chose);
	return (count);
}

int ft_search_less_a(t_stack *number_chose, t_stack **stack_a)
{
	t_stack	*tmp;
	int		count;

	tmp = *stack_a;
	count = 0;
	if (ft_sorted_a(stack_a) == 1)
	{
		while (tmp && (count == 0 || tmp != *stack_a))
		{
			if (number_chose->content < tmp->content)
				return (count);
			tmp = tmp->next;
			++count;
		}
		return (-1);
	}
	else
		count = ft_brave_a(stack_a, number_chose);
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

int	ft_sorted_a(t_stack **stack_a)
{
	int	i;
	int	length;
	t_stack	*tmp;

	tmp = *stack_a;
	length = ft_strlen_stack(*stack_a);
	if (length > 0)
	{
		i = 1;
		while (tmp && i++ < length)
		{
			if (tmp->content > tmp->next->content)
				return (-1);
			tmp = tmp->next;
		}
		return (1);
	}
	return (1);
}

void print_stack(t_stack *stack)
{
	t_stack *begin;
	int		i;

	i = 0;
	begin = stack;
	while (stack && (i == 0 || stack != begin))
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

int	ft_brave(t_stack **stack_b, t_stack *number_chose)
{
	t_stack	*tmp;
	int	indice_min;
	int	indice;

	tmp = *stack_b;
	indice_min = ft_min(stack_b);
	while (tmp && indice_min-- > 0)
		tmp = tmp->next;
	indice = ft_less_b(number_chose, stack_b);
	if (indice == -1)
	{
		tmp = *stack_b;
		indice = ft_less_b(number_chose, stack_b);
	}
	else
		indice += indice_min; 
	return (indice);
}

int	ft_brave_a(t_stack **stack_a, t_stack *number_chose)
{
	t_stack	*tmp;
	int	indice_min;
	int	indice;
	int	indice_min_tmp;

	tmp = *stack_a;
	indice_min = ft_min(stack_a);
	indice_min_tmp = indice_min;
	while (tmp && indice_min_tmp-- > 0)
		tmp = tmp->next;
	indice = ft_less_a(number_chose, &tmp);
	printf("indice : %d %d : %d\n", number_chose->content, (*stack_a)->content, indice);
	if (indice == -1)
	{
		tmp = *stack_a;
		indice = ft_less_a(number_chose, stack_a);
	}
	else
		indice = indice + indice_min;
	return (indice);
}

int	ft_less_a(t_stack *number_chose, t_stack **stack_a)
{
	int	indice;
	t_stack	*tmp_a;

	indice = 0;
	tmp_a = *stack_a;
	while (tmp_a && (indice == 0 || tmp_a != *stack_a))
	{
		if (number_chose->content < tmp_a->content)
			return (indice);
		tmp_a = tmp_a->next;
		indice++;
	}
	return (-1);
}

int	ft_less_b( t_stack *tmp, t_stack **stack_b)
{
	int	indice;
	t_stack	*tmp_b;

	indice = 0;
	tmp_b = *stack_b;
	while (tmp_b && (indice == 0 || tmp != *stack_b))
	{
		if (tmp->content < tmp->next->content)
			return (indice);
		tmp = tmp->next;
		++indice;
	}
	return (-1);
}