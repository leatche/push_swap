/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:40:24 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/12/18 09:47:23 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_byY_insertion(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 1;
	while (i < size - 2)
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->next)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_sb(stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->next)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_sb(stack_b);
		ft_pa(stack_b, stack_a);
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_sb(stack_b);
		ft_pa(stack_b, stack_a);
		ft_pa(stack_b, stack_a);
	
}
/*
void	ft_by_insertion(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
				ft_sa(stack_a);
			else
			{
				ft_pb(stack_a, stack_b);
				k = 0;
				while (k < i - j - 1)
				{
					ft_ra(stack_a);
					k++;
				}
				ft_pa(stack_b, stack_a);
				k = 0;
				while (k < i - j)
				{
					ft_rra(stack_a);
					k++;
				}
				break;
			}
			j++;
		}
		i++;
	}
}
*/