/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:34:46 by ltcherep          #+#    #+#             */
/*   Updated: 2025/01/21 03:23:02 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int ft_start(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*actual_number;
	int		count;

	stack_a = ft_create_list(argc, argv);
	stack_b = NULL;
	if (get_maximum(actual_number) == 1 || get_minimum(actual_number) == 1)
	{

	}
	ft_pb(stack_b, stack_a);// push de stack a -> stack b
	count++;
	ft_pb(stack_b, stack_a);
	count++;
	while (count + 1 != 0)
	{
		
	}
}

///// utils /////

int	get_minimum(t_stack *actual_number)
{

}
int get_maximum(t_stack *actual_number)
{

}
int	ft_count_operations;
