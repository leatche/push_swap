/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/25 16:08:41 by tcherepoff       ###   ########.fr       */
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

void	ft_five_number(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		count;

	tmp = stack_a;
	while (ft_strlen_stack(stack_a) != 3)
		ft_pb(stack_a, stack_b);
	ft_three_number(stack_a);
	ft_two_number(stack_b);
	while (stack_b != NULL)
	{
		count = ft_search_more(stack_a, stack_b);
		if (count == 0)
			ft_pb(stack_b, stack_a);
		else if (count == 1)
		{
			ft_pb(stack_b, stack_a);
			ft_sa(stack_a);
		}
		else if (count == 2 && ft_strlen_stack(stack_b) == 2)
		{
			ft_rra(stack_a, stack_b);
			ft_pb(stack_b);
		}
		else
			ft_pb(stack_b);
			ft_ra(stack_a);
		ft_ra(stack_a);
		while (is_minimum(stack_a) == -1)
			ft_rra(stack_a);
	}
}
