/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:41:16 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/05 04:36:46 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rrx(t_stack **stack)
{
	if (stack && *stack && (*stack)->prev != *stack)
		*stack = (*stack)->prev;
}

void ft_rra(t_stack **stack_a)
{
	ft_rrx(stack_a);
	ft_putstr_fd("rra\n", 1);
	// print_stack(*stack_a);
}

void ft_rrb(t_stack **stack_b)
{
	ft_rrx(stack_b);
	ft_putstr_fd("rrb\n", 1);
	// print_stack(*stack_b);
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
