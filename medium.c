/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:22:06 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/12/29 12:10:46 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_medium(t_stack **stack_a, t_stack **stack_b, int size)
{
	int			i;
	int			j;
	int			k;
	char		*b;
	int			current;

	i = 1;
	b = malloc(sizeof(int) * size);
	while (i < size)
	{
		current = stack_a[i];
		ft_pb(stack_a, stack_b); // Déplacer l'élément à trier dans b
		j = i - 1;
		while (j >= 0 && stack_b[0] < stack_a[j])
		{
			rra(stack_a,size); // Rotation à gauche pour trouver la position correcte
			j--;
		}
		pa(stack_a, stack_b); // Remettre l'élément dans a à la bonne position
		k = 0;
		while (k < i - j - 1)
		{ // Remettre les éléments déplacés à leur place
			ra(stack_a, size);
			k++;
		}
		i++;
	}
	free(b); // Libérer la mémoire allouée pour b
}

void ft_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	ft_pb(stack_a, stack_b); // Déplacer l'élément à trier dans b
	while (stack_a[i] < stack_a[j])
		j++;
	if (stack_a[i] > stack_a[j])
	{
		if (stack_a[j])
	}
}

void ft_small();//renvoie l'indice du plus petit de la chaine
