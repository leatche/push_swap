/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:25:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/01 19:18:57 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!stack || *stack == NULL || !(*stack)->next)
		return ;
	move = *stack;
	*stack = move->next;
	move->next = NULL;
	tmp = ft_lstlast(*stack);
	tmp->next = move;
}

void	ft_ra(t_stack **stack_a)
{
	ft_r(stack_a);
	ft_putstr("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	ft_r(stack_b);
	ft_putstr("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	ft_putstr("rr\n");
}
