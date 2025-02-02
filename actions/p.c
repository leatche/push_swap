/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:22:41 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/02 01:29:37 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (*stack_src == NULL)
		return ;
	tmp = *stack_src;
	*stack_src = tmp->next;
	tmp->next = *stack_dst;
	*stack_dst = tmp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_p(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_p(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
