/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:23:06 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:43:35 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	ft_middle(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	tmp = stack->next;
	count = 1;
	while (tmp && tmp != stack)
	{
		tmp = tmp->next;
		count++;
	}
	count = (count / 2) + (count % 2 == 1);
	return (count);
}

int	ft_get_index(int nbr, t_stack *stack_a)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = stack_a;
	while (tmp->content != nbr)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
