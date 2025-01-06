/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:13:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/06 14:09:11 by tcherepoff       ###   ########.fr       */
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


/* 1 fonction qui : creer une case de la liste
 ft_lstnew_bonus
on doit faire en sorte que le précedent de next soit egale a celui ci.
	1 fonction qui traduit en nombre 
	
	*/
int	ft_
void	*content;
t_stack	*new;
int count ;

count = 0;
content = malloc ;
if !...


content = ft_split(stack_a[i]);
new = ft_lstnew_bonus(content);
if (count > 0)
{
	
}
else
	ft_new_list(new);

attention a free malloc de content;

creer la nouvelle chaine et y mettre 

t_stack ft_new_list(int content )
{
	t_stack **new_stack;

	*new_stack = new;


}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Fonction utilitaire pour gérer atoi avec protection d'erreurs
int	ft_atoi_protect(const char *str, int *error) {
    long result = 0;
    int sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        if ((result * sign) > INT_MAX || (result * sign) < INT_MIN) {
            *error = 1;
            return 0;
        }
        str++;
    }
    return (int)(result * sign);
}

// Fonction pour parser et ajouter à la liste chaînée
t_stack *parse_and_create_list(const char *str) {
    t_stack *head = NULL;
    t_stack *current = NULL;
    char **numbers = NULL;
    int value, i = 0, error = 0;

    // Split la chaîne en utilisant les espaces
    numbers = ft_split(str, ' ');
    if (!numbers)
        return NULL;

    while (numbers[i]) {
        error = 0;
        value = ft_atoi_protect(numbers[i], &error);
        if (error) {
            printf("Erreur : Valeur hors limites ou invalide\n");
            return NULL;
        }

        t_stack *new_node = lstnew(value);
        if (!new_node)
            return NULL;

        if (!head)  // on creer le lien !!!!=
            head = new_node;
        else
            current->next = new_node;
        
        current = new_node;
        i++;
    }
    
    // Libérer la mémoire du tableau de split
    i = 0;
    while (numbers[i])
        free(numbers[i++]);
    free(numbers);

    return head;
}


