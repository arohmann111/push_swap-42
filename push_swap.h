#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int		num;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

int	input_check(int ac, char **av);

#endif