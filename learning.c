/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:02:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/01/09 19:02:57 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	new_element(int nbr, t_pile **elem)
{
	(*elem) = malloc(sizeof(t_pile));
	if (!(*elem))
		return (-1);
	(*elem)->value = nbr;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	return (1);
}