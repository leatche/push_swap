/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neww.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:24:49 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/01 22:52:04 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_element(int nbr, t_stack *elem)
{
	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (-1);
	elem->content = nbr;
	elem->next = NULL;
	elem->prev = NULL;
	return (1);
}

int	add_to_list(t_stack *pile, int nbr)
{
	t_stack	*elem;


	if (new_element(nbr, elem) == -1)
		return (-1);
	if (pile == NULL)
	{
		pile = elem;
		pile->next = pile;
		pile->prev = pile;
	}
	else
	{
		elem->prev = pile->prev;
		elem->next = pile;
		pile->prev->next = elem;
		pile->prev = elem;
		pile = elem;
	}
	return (1);
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

void	ft_p(t_stack *stack_src, t_stack *stack_dst)
{
	t_stack	*tmp;

	if (!stack_src)
		return ;
	add_to_list(stack_dst, stack_src->content);
	tmp = stack_src;
	stack_src->prev->next = stack_src->next;
	stack_src->next->prev = stack_src->prev;
	stack_src = stack_src->next;
	free(tmp);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_p(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
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

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = create_node(3);
    stack_b->next = create_node(2);
    stack_b->next->prev = stack_b;
    stack_b->next->next = create_node(1);
    stack_b->next->next->prev = stack_b->next;

    printf("Avant ft_pa :\n");
    printf("Stack A : ");
    print_stack(stack_a);
    printf("Stack B : ");
    print_stack(stack_b);

    ft_pa(stack_a, stack_b);

    printf("\nAprès ft_pa :\n");
    printf("Stack A : ");
    print_stack(stack_a);
    printf("Stack B : ");
    print_stack(stack_b);

    free(stack_a);
    free(stack_b->next);
    free(stack_b);
    return 0;
}