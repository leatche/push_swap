/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:00:29 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/16 17:58:55 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_error(void)
{
	write (2, "Error : il n'y a pas que des chiffres\n", 39);
	exit(1);
}

void	ft_letter(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

int	ft_check_bad_position(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (-1);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_letter_bad_position(char **argv)
{
	ft_letter(argv);
	if (ft_check_bad_position(argv, 1, 0) == -1)
	{
		printf("Error: de caractere.\n");
		return (-1);
	}
	return (0);
}

int	ft_check_duplicate(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*move;
	int		count;

	tmp = stack_a;
	count = 0;
	while (tmp && tmp->next != stack_a)
	{
		move = tmp->next;
		if (count == 0)
		{
			if (tmp->content == move->content)
				return (-1);
			count++;
		}
		while (move && move->next != tmp->next)
		{
			if (tmp->content == move->content)
				return (-1);
			move = move->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
