/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/05 05:00:10 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_two_number_a(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp && tmp->next->content < tmp->content)
		ft_sa(stack_a);
}

void	ft_two_number_b(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp && tmp->next->content > tmp->content)
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

void	ft_five_number(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	while (ft_strlen_stack(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
	ft_three_number(stack_a);
	ft_two_number_b(stack_b);
	while (ft_strlen_stack(*stack_b) > 0)
	{
		count = ft_search_less_a(*stack_b, stack_a);
		while (count-- > 0)
			ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
	}
	ft_ra_or_rra(stack_a);
	print_stack(*stack_a);
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
