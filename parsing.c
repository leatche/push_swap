/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:13:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/06 17:57:30 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(t_stack **stack)
{
	int	i;
	int	j;

	i = 0;
	if (!stack || !*stack)
		return (0);
	while (stack[i])
	{
		j = i + 1;
		while (stack[i] != stack[j] && stack[j])
			j++;
		if (stack[i] == stack[j])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_parsing(t_stack **stack_a)
{
	int	a;

	a = ft_duplicate(stack_a);

	if (a == 0)
		return (NULL);
}


/* 1 fonction qui : creer une case de la liste
 ft_lstnew_bonus
on doit faire en sorte que le précedent de next soit egale a celui ci.
	1 fonction qui traduit en nombre

	*/
t_stack	*ft_number(const char *str)
{

}

t_stack	*new_list(const char *str)
{
	t_stack	*start;
	t_stack	*current;
	t_stack *new_node;
	char **numbers;
	int value;
	int i;
	int	error;

	start = NULL;
	current = NULL;
	numbers = NULL;
	i = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (NULL);
	while (numbers[i])
	{
		value = ft_atoi(numbers[i]);
		new_node = lstnew(value);
		if (!new_node)
			return NULL;
		if (!start)
			start = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);

	return (start);
}
