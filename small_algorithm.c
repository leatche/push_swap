/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/04 23:54:21 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_two_number(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp && tmp->next->content < tmp->content)
		ft_sa(stack_a);
}

void	ft_three_number(t_stack **stack_a)
{
	int	tmp;
	int	tmp1;
	int	tmp2;

	tmp = (*stack_a)->content;
	tmp1 = (*stack_a)->next->content;
	tmp2 = (*stack_a)->prev->content;
	if ((tmp < tmp1) && (tmp1 < tmp2))
		return ;
	else if ((tmp < tmp1) && (tmp1 > tmp2) && (tmp < tmp2))
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if ((tmp < tmp1) && (tmp1 > tmp2) && (tmp > tmp2))
		ft_rra(stack_a);
	else if ((tmp > tmp1) && (tmp1 < tmp2) && (tmp > tmp2))
		ft_ra(stack_a);
	else if ((tmp > tmp1) && (tmp1 > tmp2))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else
		ft_sa(stack_a);
}


void	ft_four_number(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	ft_pb(stack_a, stack_b);
	ft_three_number(stack_a);
	ft_pa(stack_a, stack_b);
	if (is_maximum(tmp, *stack_a) == 1)
		ft_ra(stack_a);
	else if (is_minimum(tmp, *stack_a) == 1)
		return ;
	else if ((tmp->content > tmp->next->content) && (tmp->content
			> tmp->next->next->content))
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else
		ft_sa(stack_a);
}

void	ft_five_number(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		index_min;
	int		index_tmp;
	int		index_little;
	
	tmp = *stack_a;
	index_min = ft_min(stack_a);
	index_tmp = 0;
	index_little = ft_little(stack_a);
	while (ft_strlen_stack(*stack_b) != 2)
	{
		if (tmp && (index_min == index_tmp || index_little == index_tmp))
			ft_pb(stack_a, stack_b);
		else
		{
			ft_rra(stack_a);
			index_min = ft_min(stack_a);
			index_little = ft_little(stack_a);
		}
	}
	ft_three_number(stack_a);
	ft_two_number(stack_b); // trié dans l'autre sens 
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

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
	index = 0;
	min_index = 0;
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


int	ft_little(t_stack **stack_a)
{
	t_stack	*tmp;
	int		index;
	int		index_min;
	int		little;
	t_stack	*little_point;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (-1);
	index_min = ft_min(stack_a);
	tmp = *stack_a;
	index = 0;
	little = 0;
	little_point = NULL;
	while (tmp != *stack_a || index == 0)
	{
		if (index != index_min && (!little_point || tmp->content < little_point->content))
		{
			little_point = tmp;
			little = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (little);
}
