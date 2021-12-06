# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 11:04:41 by arohmann          #+#    #+#              #
#    Updated: 2021/12/06 12:26:38 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJDIR = obj

CFLAGS = -Wall -Werror -Wextra -c
SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_atod_bonus.c \
ft_atol_bonus.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_free_split_bonus.c \
ft_free_arr_bonus.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strcmp_bonus.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c

BONI = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
OBJ_B = $(BONI:%.c=$(OBJDIR)/%.o)

all: bonus
	
$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJDIR)/*.o

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $< -o $@

bonus: $(OBJ) $(OBJ_B)
	ar -crs $(NAME) $(OBJDIR)/*.o

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	
re: fclean all


	
	