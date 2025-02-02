# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 08:50:30 by tcherepoff        #+#    #+#              #
#    Updated: 2025/02/02 01:56:12 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_PARSING =	parsing/parsing.c		\
				parsing/type_error.c	\
				parsing/utils_error.c	\

SRCS_ACTIONS =	actions/p.c				\
				actions/r.c				\
				actions/rr.c			\
				actions/s.c				\

SRCS_ALGO =		algorithm.c				\
				big_algorithm.c			\
				small_algorithm.c		\

SRCS = $(SRCS_PARSING) $(SRCS_ACTIONS) $(SRCS_ALGO)

OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Werror -Wextra -Ilibft -I.
LDFLAG = ./libft/libft.a
RM = rm -f
AR = ar rcs

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
