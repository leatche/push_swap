/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:51:20 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/21 01:43:57 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_type_sort(t_stack **stack_a)
{
	int		size;
	t_stack	**stack;

	size = 0;
	if (!stack || *stack == NULL)
		return ;
	size = ft_lstsize(stack_a);
	if (size < 2)
		return (**stack_a);
	if (size > 1 && size < 5)
		stack = ft_by_insertion(stack_a, size);
	if (size > 4 && size < 51)
		stack = ft_medium(stack_a, size)

}
