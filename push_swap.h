#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define GREEN  "\x1B[32m"
#define CVIO  "\x1B[35m"
#define RED  "\x1B[31m"
#define YELL  "\x1B[33m"
#define CYAN  "\x1B[36m"
#define RE  "\x1B[0m"

typedef struct s_node
{
	int		num;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

int	input_check(int ac, char **av);

#endif