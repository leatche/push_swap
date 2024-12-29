# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 08:50:30 by tcherepoff        #+#    #+#              #
#    Updated: 2024/12/12 08:52:01 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRCS = checker.c     push_swap.c

OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Werror -Wextra -Ilibft
RM = rm -f
AR = ar rcs

.c.o:
			$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)
			

re:			fclean all

rebonus: fclean
