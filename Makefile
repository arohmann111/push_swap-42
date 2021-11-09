# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:58:55 by arohmann          #+#    #+#              #
#    Updated: 2021/11/04 17:39:53 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -Ilibft -Llibft -lft
LPATH = ./libft/

SRC = main.c \
input.c \
nodes.c \
push.c \
rev_rotate.c \
rotate.c \
swap.c \
print.c 
#%.o: %.c
#	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: libft all clean fclean re bonus $(NAME)

all: $(NAME)

$(NAME): libft
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) -o $(NAME)

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

