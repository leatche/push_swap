/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:25:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/16 17:53:54 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	print_stack(t_stack *stack)
{
	t_stack *begin;
	int		i;
	if (DEBUG == 0)
		return ;

	i = 0;
	begin = stack;
	while (stack && (i == 0 || stack != begin))
	{
		printf("%d ", stack->content);
		i++;
		stack = stack->next;
	}
	printf("\n");
}
*/

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
