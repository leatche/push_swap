/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:52:14 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/12/16 18:12:36 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_box {
	int			content;
	struct s_box *next;
}				 t_box;

typedef struct t_stack {
	int				content;
	struct t_stack *next;
}				 t_stack;

#endif