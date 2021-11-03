# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:58:55 by arohmann          #+#    #+#              #
#    Updated: 2021/11/03 17:41:42 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra -Ilibft -Llibft -lft

LPATH = ./libft/

SRC = main.c \
nodes.c \
push.c \
rev_rotate.c \
rotate.c \
swap.c \
print.c 

.PHONY: libft all clean fclean re bonus $(NAME)

all: $(NAME)

$(NAME): libft
	gcc $(FLAGS) $(SRC) -o $(NAME)

libft:
	make -C $(LPATH)

clean:
	rm -f *.o *~
	make clean -C $(LPATH)

fclean: clean
	rm -f push_swap
	make clean -C $(LPATH)

re: fclean all

bonus:

