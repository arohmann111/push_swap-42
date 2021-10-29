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

typedef struct s_data
{
	t_node	*head_a;
	t_node	*head_b;
} t_data;

int	input_check(int ac, char **av);

/**********************************************************/
/*                      INSTRUCTIONS                      */
/**********************************************************/

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif