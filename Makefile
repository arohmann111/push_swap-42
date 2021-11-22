# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:58:55 by arohmann          #+#    #+#              #
#    Updated: 2021/11/22 16:33:28 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -Ilibft -Llibft -lft
LPATH = ./libft/

OBJDIR = obj

SRC = push_swap.c \
input.c \
nodes.c \
push.c \
rev_rotate.c \
rotate.c \
swap.c \
init.c \
sort_small.c \
sort_big.c \
lo_in_seq.c \
print.c 

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: libft all clean fclean re bonus $(NAME)

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJDIR)/*.o -o $(NAME)

libft:
	make -C $(LPATH)

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LPATH)

fclean: clean
	rm -f $(NAME)
	make clean -C $(LPATH)

re: fclean all

bonus:

