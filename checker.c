/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:45:38 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/12/13 15:18:00 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

// Récupérer le sommet de stack_a ( ce qui est au top c'st le plus recent )
int	ft_top(t_stack *stack)
{
	if (stack)
		return (stack);
	return (NULL);
}
void insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	value;
	// Étape 1 : Transférer tous les éléments de stack_a à stack_b triés
	while (ft_empty(stack_a) == 0)
	{
		value = ft_top(stack_a);
		push_in_sorted_order(stack_b, value); // Placer dans stack_b de manière triée
	}

    // Étape 2 : Replacer les éléments triés dans stack_a
    while (!is_empty(stack_b))
    {
        push(stack_a, pop_top(stack_b)); // Récupérer le sommet de stack_b et le placer dans stack_a
    }
}
