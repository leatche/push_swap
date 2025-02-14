/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:05:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/12 04:07:04 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_min(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*min;
	int		index;
	int		min_index;
	
	if (!stack_a || !*stack_a)
		return (-1);
	min = *stack_a;
	tmp = (*stack_a)->next;
	index = 1;
	min_index = 1;
	while (tmp != *stack_a)
	{
		index++;
		if (tmp->content < min->content)
		{
			min = tmp;
			min_index = index;
		}
		tmp = tmp->next;
	}
	return (min_index);
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