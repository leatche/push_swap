/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/16 17:25:33 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_list(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_check_letter_bad_position(argv) == -1)
	{
		printf("Error: de caractere.\n");
		free_stack(stack_a);
		return (-1);
	}
	else if (ft_check_duplicate(stack_a) == 0)
	{
		printf("Error: duplicat.\n");
		free_stack(stack_a);
		return (-1);
	}
	if (ft_sorted_a(&stack_a) == -1)
		ft_executate(&stack_a, &stack_b);
	free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}

void ft_executate(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strlen_stack(*stack_a) == 1 || ft_strlen_stack(*stack_a) == 0)
		return ;
	else if (ft_strlen_stack(*stack_a) == 2)
		ft_two_number_a(stack_a);
	else if (ft_strlen_stack(*stack_a) == 3)
		ft_three_number(stack_a);
	else if (ft_strlen_stack(*stack_a) == 5 || ft_strlen_stack(*stack_a) == 4)
		ft_five_number(stack_a, stack_b);
	else
		ft_big_algorithm(stack_a, stack_b);
}
