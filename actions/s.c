/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:21 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/01 19:18:42 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_stack **stack_a)
{
	ft_s(stack_a);
	ft_putstr("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	ft_s(stack_b);
	ft_putstr("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	ft_putstr("ss\n");
}
