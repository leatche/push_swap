/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:25:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/02 23:27:14 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_stack **stack)
{
	if (stack && (*stack) && (*stack)->next != *stack)
		(*stack) = (*stack)->next;
}

void	ft_ra(t_stack **stack_a)
{
	ft_r(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stack_b)
{
	ft_r(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	ft_putstr_fd("rr\n", 1);
}
