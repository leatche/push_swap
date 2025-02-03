/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:21 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/03 00:53:08 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	ft_sa(t_stack **stack_a)
{
	ft_s(stack_a);
	ft_putstr_fd("sa\n", 1);
	print_stack(*stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	ft_s(stack_b);
	ft_putstr_fd("sb\n", 1);
	print_stack(*stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	ft_putstr_fd("ss\n", 1);
	print_stack(*stack_a);
	print_stack(*stack_b);
}
