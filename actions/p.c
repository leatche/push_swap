/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:22:41 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/03 00:53:49 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_stack **pile_source, t_stack **pile_dest)
{
	if (!pile_source || *pile_source == NULL)
		return ;
	ft_add_new_element((*pile_source)->content, pile_dest);
	(*pile_source)->prev->next = (*pile_source)->next;
	(*pile_source)->next->prev = (*pile_source)->prev;
	(*pile_source) = (*pile_source)->next;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_p(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
	print_stack(*stack_a);
	print_stack(*stack_b);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_p(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
	print_stack(*stack_a);
	print_stack(*stack_b);
}


int	ft_add_new_element(int nbr, t_stack **stack_tmp)
{
	t_stack	*new_element;

	if (ft_create_element(nbr, &new_element) == 0)
		return (0);
	if (!(*stack_tmp))
	{
		(*stack_tmp) = new_element;
		(*stack_tmp)->next = *stack_tmp;
		(*stack_tmp)->prev = *stack_tmp;
	}
	else
	{
		new_element->prev = (*stack_tmp)->prev;
		new_element->next = (*stack_tmp);
		(*stack_tmp)->prev->next = new_element;
		(*stack_tmp)->prev = new_element;
		(*stack_tmp) = new_element;
	}
	return (1);
}