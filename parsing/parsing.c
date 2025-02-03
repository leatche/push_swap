/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:13:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/03 00:46:25 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*ft_create_list(int argc, char **argv)
{
	t_stack	*list;
	char	**new;
	int		i;
	int		j;

	list = NULL;
	if (argc <= 1)
		ft_error();
	i = 1;
	while (i < argc)
	{
		new = ft_split(argv[i], ' ');
		j = 0;
		while (new[j] != NULL)
		{
			ft_add_to_parse_new_element(ft_atoi(new[j]), &list);
			free(new[j]);
			j++;
		}
		free(new);
		i++;
	}
	return (list);
}

int	ft_create_element(int nbr, t_stack **new_element)
{
	(*new_element) = malloc(sizeof(t_stack));
	if (!(*new_element))
		return (0);
	(*new_element)->content = nbr;
	(*new_element)->next = NULL;
	(*new_element)->prev = NULL;
	return (1);
}

int	ft_add_to_parse_new_element(int nbr, t_stack **stack_tmp)
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
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	current = stack;
	while (current->next != stack)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	stack = NULL;
}

 int	ft_parsing(int argc, char **argv)
 {
 	t_stack	*stack_a;

 	stack_a = NULL;
	stack_a = ft_create_list(argc, argv);
	if (ft_check_letter_bad_position(argv) == -1)
	{
		printf("Error: de caractere.\n");
		free_stack(stack_a);
		return (0);
	}
	else if (ft_check_duplicate(stack_a) == 0)
	{
		printf("Error: duplicat.\n");
		free_stack(stack_a);
		return (0);
	}
	else
	{
		printf("la chaine est donc : \n");
		print_stack(stack_a);
	}
	free_stack(stack_a);
	return (0);
}
