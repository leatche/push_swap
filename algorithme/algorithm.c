/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/14 20:10:51 by tcherepoff       ###   ########.fr       */
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
	if (ft_check_letter_bad_position(argv) == -1)
	{
		printf("Error: de caractere.\n");
		free_stack(stack_a);
		return (-1);
	}
	else if (ft_check_duplicate(stack_a) == 0)
	{
		printf("Error: duplicat.\n");
		free_stack(stack_a);
		return (-1);
	}
	// else
	// {
	// 	printf("la chaine est donc : \n");
	// 	print_stack(stack_a);
	// }
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

	// printf("ft_where_top a été utilisé\n");
	count_top = ft_count_top_of_top(number_chose, stack_a, stack_b);
	count_bottom = ft_count_bottom_of_top(number_chose, stack_a, stack_b);
	if (DEBUG)
	printf("ft_where_top for %d, %d %d\n", number_chose->content, count_top, count_bottom);
	if (count_top <= count_bottom)
		return (count_top);
	else
		return (count_bottom);

}

int	ft_where_bottom(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count_top;
	int count_bottom;
	
	//printf("ft_where_bottom a été utilisé\n");
	count_top = ft_count_top_of_bottom(number_chose, stack_a, stack_b);
	count_bottom = ft_count_bottom_of_bottom(number_chose, stack_a, stack_b);
	if (DEBUG)
		printf("ft_where_bottom for %d, %d %d\n", number_chose->content, count_top, count_bottom);
	//printf("%d count top \n", count_top);
	//printf("%d count bottom \n", count_bottom);
	if (count_top <= count_bottom)
		return (count_top);
	else
		return (count_bottom);
}

///////////////////////////////////tous les types de count /////////////////////////////////////////////////////////

int ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	ft_count_top_of_top(t_stack *number_chose, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	index;
	int	win;
	int count_move;

	// printf("%d\n", number_chose->content);
	count = ft_search_less_b(number_chose, &stack_b);
	index = ft_get_index(number_chose->content, stack_a) - 1;
	index = index % ft_strlen_stack(stack_a);
	count = count % ft_strlen_stack(stack_b);

	// printf("ft_count_top_top %d %d\n", count, index);
	
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
	// printf("%d count \n", count);
	index = ft_get_index(number_chose->content, stack_a) - 1;
	index = index % ft_strlen_stack(stack_a);
	count = count % ft_strlen_stack(stack_b);
	// printf("%d index \n", index);
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

	// printf("count_top_bottom %d %d\n", count, index);
	// if (ft_strlen_stack(stack_a) == 1)
	// 	index = 0;
	// printf("%d index \n", index);
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

/////////UTILS∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕∕/


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
	count = (count / 2) + (count % 2 == 1);
	return (count);
}


int ft_search_less_b(t_stack *number_chose, t_stack **stack_b)
{
	t_stack	*tmp;
	int		count;

	tmp = *stack_b;
	count = 0;
	if (ft_sorted_b(stack_b) == 1)
	{
		while (tmp && (count == 0 || tmp != *stack_b))
		{
			if (number_chose->content > tmp->content)
				return (count);
			tmp = tmp->next;
			++count;
		}
		return (0);
	}
	else
		count = (ft_brave_b(stack_b, number_chose) % ft_strlen_stack(*stack_b));
	// if (DEBUG == 1)
	// 	printf("donne moi le count : %d, le nombre choisi %d\n", count, number_chose->content);
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

int	ft_get_index(int nbr, t_stack *stack_a)
{
	int	i;
	t_stack	*tmp;

	i = 1;
	tmp = stack_a;
	while (tmp->content != nbr)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void print_stack(t_stack *stack)
{
	t_stack *begin;
	int		i;
	if (DEBUG == 0)
		return ;

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

int	ft_brave_b(t_stack **stack_b, t_stack *number_chose)
{
	t_stack	*tmp;
	int	indice_min;
	int	indice;
	int	indice_min_tmp;

	tmp = *stack_b;
	indice_min = ft_min(stack_b);
	// printf("minimum de la stack %d\n", indice_min);
	indice_min_tmp = indice_min;
	while (tmp && indice_min_tmp-- > 0)
		tmp = tmp->next;
	indice = ft_less_b(number_chose, &tmp) % ft_strlen_stack(*stack_b);
	if (is_maximum(number_chose, *stack_b) == 1)
		indice = indice_min;
	else if (is_minimum(number_chose, *stack_b) == 1)
		indice = indice_min;
	else if (indice == -1)
	{
		tmp = *stack_b;
		indice = ft_less_b(number_chose, stack_b);
		// printf("max");
	}
	else
	{
		indice = indice + indice_min;
		// printf("min");
	}
	// if (DEBUG)
	// 	printf(" indice  : %d\n", indice % ft_strlen_stack(*stack_b));
	return (indice);
}


int	ft_less_b( t_stack *number_chose, t_stack **stack_b)
{
	int	indice;
	t_stack	*tmp_b;

	indice = 0;
	tmp_b = *stack_b;
	while (indice == 0 || tmp_b->content != (*stack_b)->content)
	{
		if (number_chose->content > tmp_b->content)
			return (indice);
		tmp_b = tmp_b->next;
		indice++;
	}
	// printf("maxnklezfnkleznezklnkmez,kmEzkmneznklmfez");
	return (-1);
}
