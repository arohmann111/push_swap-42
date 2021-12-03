# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:58:55 by arohmann          #+#    #+#              #
#    Updated: 2021/12/03 13:28:45 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CH = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -Ilibft -Llibft -lft
LPATH = ./libft/

OBJDIR = obj

SRC = push_swap.c \
input.c \
nodes.c \
opti.c \
opti_utils.c \
push.c \
rev_rotate.c \
rotate.c \
swap.c \
init.c \
sort_small.c \
sort_big.c \
lo_in_seq.c \
utils.c \
print.c \
main.c

SRC_CH = checker.c \
init.c \
input.c \
nodes.c \
push.c \
rev_rotate.c \
rotate.c \
swap.c \
print.c \
get_next_line.c \
push_swap.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
OBJ_CH = $(SRC_CH:%.c=$(OBJDIR)/%.o) 

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@



.PHONY: libft all clean fclean re bonus $(NAME) $(NAME_CH)

all: $(NAME) $(NAME_CH)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)
	
$(NAME_CH): libft $(OBJ_CH)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_CH) -o $(NAME_CH)

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
