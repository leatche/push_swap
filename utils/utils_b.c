/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:11:26 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:52:59 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_b(t_stack **stack_b)
{
	int		i;
	int		length;
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

int	ft_search_less_b(t_stack *number_chose, t_stack **stack_b)
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
	return (count);
}

int	ft_less_b( t_stack *number_chose, t_stack **stack_b)
{
	int		indice;
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
	return (-1);
}

int	ft_brave_b(t_stack **stack_b, t_stack *number_chose)
{
	t_stack	*tmp;
	int		indice_min;
	int		indice;
	int		indice_min_tmp;

	tmp = *stack_b;
	indice_min = ft_min(stack_b);
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
	}
	else
		indice = indice + indice_min;
	return (indice);
}
