/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:13:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/20 17:49:03 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(char *)s = 0;
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if ((size >= 65535 && count >= 65535) || size * count >= 65535)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
char	*ft_strdup(const char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}


int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9') && !(str[i] == '-' || str[i] == '+'))
		i++;
	minus = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	result *= minus;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (result);
}


static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	**ft_alloc(char **list, char const *s, char c, size_t count)
{
	size_t	j;
	size_t	k;
	size_t	word;

	word = 0;
	j = 0;
	while (word < count)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			j++;
			k++;
		}
		list[word] = ft_calloc(k + 1, sizeof(char));
		if (!list)
			return (NULL);
		word++;
	}
	return (list);
}

static char	**ft_fill(char **list, char const *s, char c, size_t count)
{
	size_t	j;
	size_t	k;
	size_t	word;

	word = 0;
	j = 0;
	while (word < count)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			list[word][k] = s[j];
			j++;
			k++;
		}
		word++;
	}
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	count;

	if (!s)
		return (NULL);
	list = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!list)
		return (NULL);
	count = ft_count(s, c);
	list = ft_alloc(list, s, c, count);
	list = ft_fill(list, s, c, count);
	return (list);
}

static t_stack *ft_create_list(int argc, char **argv)
{
	t_stack	*list = NULL;
	char	**new;
	int		i;
	int		j;

	if (argc <= 1)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		new = ft_split(argv[i], ' ');
		j = 0;
		while (new[j] != NULL)
		{
			ft_add_new_element(ft_atoi(new[j]), &list);
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
	{
		free(new_element);
		return (0);
	}
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

int	ft_check_duplicate(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*move;

	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		move = tmp->next;
		while (move->next != tmp)
		{
			if (tmp->content == move->content)
				return (0);
			move = move->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	print_stack(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
	{
		printf("head est null");
		return ;
	}
	current = head;
	while (current->next != head)
	{
		printf("[%d] ", current->content);
		current = current->next;
	}
	printf("[%d]\n", current->content);
	}

void free_stack(t_stack *stack)
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

int	main(int argc, char **argv)
{
	t_stack *stack_a;

	stack_a = NULL;
	stack_a = ft_create_list(argc, argv);
	if (ft_check_duplicate(stack_a) == 0)
	{
		printf("Error: duppp.\n");
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
