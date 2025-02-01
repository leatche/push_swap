/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:41:16 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/01 19:17:42 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*before;

	if (*stack == NULL || !stack || !(*stack)->next)
		return ;
	tmp = ft_lstlast(*stack);
	before = *stack;
	while (before->next != tmp)
		before = before->next;
	tmp->next = *stack;
	*stack = tmp;
	before->next = NULL;
}

void	ft_rra(t_stack **stack_a)
{
	ft_rrx(stack_a);
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	ft_rrx(stack_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
	ft_putstr("rrr\n");
}
