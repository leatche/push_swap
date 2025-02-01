/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/01 18:39:24 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_two_number(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (tmp->next < tmp)
		ft_sa(stack_a);
}
void	ft_three_number(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp = stack_a;
	tmp1 = tmp->next;
	tmp2 = tmp->prev;
	if (tmp && tmp1 > tmp && tmp2 > tmp1)
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

void	ft_four_number(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	ft_pb(stack_b, stack_a);
	ft_three_number(stack_a);
	ft_pa(stack_a, stack_b);
	tmp = stack_a;
	if (is_maximum(tmp, stack_a) == 1)
		return ;
	else if (is_minimum(tmp, stack_a) == 1)
		ft_ra(stack_a);
	else if ((tmp->content < tmp->next->content) && (tmp->content > tmp->prev->content))
		ft_sa(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	
}

void	ft_five_number(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*min;
	t_stack	*little;

	tmp = stack_a;
	min = ft_min(stack_a);
	little = ft_little(stack_a, min);
	while (ft_strlen_stack(stack_b) != 2)
	{
		if (tmp == min || tmp == little)
			ft_pb(stack_b, stack_a);
		else if (tmp->next == min || tmp->next == little)
		{
			ft_sa(stack_a);
			ft_pb(stack_b, stack_a);
		}
		else
			ft_rra(stack_a);
	}
	ft_three_number(stack_a);
	ft_two_number(stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

t_stack	*ft_min(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = stack_a->next;
	min->content = stack_a->content;
	while (tmp != stack_a)
	{
		if (tmp->content < min->content)
			min->content = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_little(t_stack *stack_a, t_stack *min)
{
	t_stack	*tmp;
	t_stack	*little;

	tmp = stack_a->next;
	if (stack_a->content == min->content)
		little->content = stack_a->next->content;
	else
		little->content = stack_a->content;
	while (tmp != stack_a)
	{
		if (tmp->content != min->content && tmp->content < little->content)
			min->content = tmp->content;
		tmp = tmp->next;
	}
	return (little);
}