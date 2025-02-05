/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:57:38 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/05 05:00:13 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

void	ft_ra_or_rra(t_stack **stack_a)
{
	int	min;
	int	min_bottom;

	min = ft_min(stack_a);
	min_bottom = ft_strlen_stack(*stack_a) - min;
	if (ft_sorted_a(stack_a) == -1)
	{
		if (min < min_bottom)
		{
			while (min-- > 0)
				ft_ra(stack_a);
		}
		else
		{
			while (min_bottom-- > 0)
				ft_rra(stack_a);
		}
	}
}