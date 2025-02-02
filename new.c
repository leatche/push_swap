/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:05:55 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/02 01:36:08 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
//# include "push_swap.h"



typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;


t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}


void	ft_s(t_stack *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}
void	ft_r(t_stack *stack)
{
	if (stack && stack->next != stack)
		stack = stack->next;
}

void	ft_ra(t_stack *stack_a)
{
	ft_r(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void ft_rrx(t_stack **stack)
{
	if (stack && *stack && (*stack)->prev != *stack)
		*stack = (*stack)->prev;
}

void ft_rra(t_stack **stack_a)
{
	ft_rrx(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_sa(t_stack *stack_a)
{
	ft_s(stack_a);
	ft_putstr_fd("sa\n", 1);
}


void	ft_three_number(t_stack **stack_a)
{
	int	tmp;
	int	tmp1;
	int	tmp2;

	tmp = (*stack_a)->content;
	tmp1 = (*stack_a)->next->content;
	tmp2 = (*stack_a)->prev->content;
	if (tmp && tmp1 > tmp && tmp2 > tmp1)
		return ;
	else if ((tmp < tmp1) && (tmp1 > tmp2) && (tmp < tmp2))
	{
		ft_rra(stack_a);
		ft_sa(*stack_a);
	}
	else if ((tmp < tmp1) && (tmp1 > tmp2) && (tmp > tmp2))
		ft_rra(stack_a);
	else if ((tmp > tmp1) && (tmp1 < tmp2) && (tmp > tmp2))
		ft_ra(*stack_a);
	else if ((tmp > tmp1) && (tmp1 > tmp2))
	{
		ft_sa(*stack_a);
		ft_rra(stack_a);
	}
	else
		ft_sa(*stack_a);
}


t_stack *create_node(int content)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
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

int	ft_add_new_element(int nbr, t_stack **stack_tmp)
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
		(*stack_tmp) = new_element;
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

int main()
{
	t_stack *stack_a = NULL;

	ft_add_new_element(-1, &stack_a);
	ft_add_new_element(2, &stack_a);
	ft_add_new_element(3, &stack_a);

	printf("Avant le tri : ");
	print_stack(stack_a);

	ft_three_number(&stack_a);

	printf("Après le tri : ");
	print_stack(stack_a);

	free_stack(stack_a);
	// free(stack_a->next->next);
	// free(stack_a->next);
	// free(stack_a);
	return 0;
}
