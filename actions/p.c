/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:22:41 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:39:51 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_stack **pile_source, t_stack **pile_dest)
{
	t_stack	*dest;

	if (!pile_source || *pile_source == NULL)
		return ;
	dest = *pile_dest;
	(*pile_dest) = *(pile_source);
	(*pile_source)->next->prev = (*pile_source)->prev;
	(*pile_source)->prev->next = (*pile_source)->next;
	if ((*pile_source) == (*pile_source)->next)
		(*pile_source) = NULL;
	else
		(*pile_source) = (*pile_source)->next;
	if (!dest)
	{
		(*pile_dest)->next = (*pile_dest);
		(*pile_dest)->prev = (*pile_dest);
	}
	else
	{
		(*pile_dest)->next = dest;
		(*pile_dest)->prev = dest->prev;
		(*pile_dest)->next->prev = (*pile_dest);
		(*pile_dest)->prev->next = (*pile_dest);
	}
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
