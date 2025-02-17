# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 08:50:30 by tcherepoff        #+#    #+#              #
#    Updated: 2025/02/16 17:36:40 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_PARSING =	parsing/parsing.c				\
				parsing/type_error.c			\
				parsing/utils_error.c			\

SRCS_ACTIONS =	actions/p.c						\
				actions/r.c						\
				actions/rr.c					\
				actions/s.c						\

SRCS_ALGO =		algorithme/algorithm.c			\
				algorithme/big_algorithm.c		\
				algorithme/small_algorithm.c	\

SRCS_UTILS =	utils/utils_a.c					\
				utils/utils_min.c				\
				utils/calcul.c					\
				utils/count.c					\
				utils/place.c					\
				utils/stack.c					\
				utils/utils_b.c					\
				utils/where.c					\

SRCS = $(SRCS_PARSING) $(SRCS_ACTIONS) $(SRCS_ALGO) $(SRCS_UTILS)

OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Werror -Wextra -Ilibft -I. -g3 -fsanitize=address
LDFLAG = ./libft/libft.a
RM = rm -f
AR = ar rcs
CC = gcc

.c.o:
			$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(FLAG) $(OBJS) $(LDFLAG) -o $(NAME)

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
