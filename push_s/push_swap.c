/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:51:20 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/09 19:14:26 by tcherepoff       ###   ########.fr       */
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





void insertion_sort_list(t_box **stack)
{
	t_box		*sorted;
	t_box	*tmp;
	t_box	*tmp_next;

	tmp = *stack;
	sorted = NULL;
	while (tmp)
	{
		tmp_next = tmp->next; //adresse du prochain noeud 
		sorted_insert(&sorted, tmp);
		tmp = tmp_next;
	}
	*stack = sorted; // pointe sur la liste trié
}

void sorted_insert(t_box **sorted, t_box *new_node) {
	// Cas 1 : La liste triée est vide ou le nouvel élément est plus petit que le premier
	if (*sorted == NULL || (*sorted)->content >= new_node->content) {
		new_node->next = *sorted;
		*sorted = new_node;
	} else {
		// Parcours pour trouver la bonne position d'insertion
		t_box *tmp = *sorted;
		while (tmp->next != NULL && tmp->next->content < new_node->content) {
			tmp = tmp->next;
		}

		// Insère le nouvel élément après `tmp`
		new_node->next = tmp->next;
		tmp->next = new_node;
	}
}

int	push_swap(int argc, char **argv)
{
	char	*new;

	if (argc == 1)
		exit(1);
	new = malloc(sizeof());
}