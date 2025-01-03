/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:13:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/03 14:30:46 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_good(t_stack **stack)
{

}
int	ft_duplicate(t_stack **stack)
{
	int	i;
	int	j;

	i = 0;
	if (!stack || !*stack)
		return (0);
	if (ft_good == 0)
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