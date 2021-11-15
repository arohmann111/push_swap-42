#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

#define GREEN  "\033[32m"
#define VIO  "\033[35m"
#define RED  "\033[31m"
#define YELL  "\033[33m"
#define CYAN  "\033[36;1m"
#define RE  "\033[0m"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_data
{
	t_node			*head_a;
	t_node			*head_b;
	t_node			*stack;
	int				size;
	int				*arr;
} t_data;

void	create_stack_a(t_data *data);
void	check_input(int	ac, char **av, t_data *data);
t_data	*init_data(void);
void	free_error(t_node *head_a, t_node *head_b, int *arr);
/**********************************************************/
/*                        PRINT                           */
/**********************************************************/
void	print(t_data *data);
void	printa(t_data *data);
void	printb(t_data *data);
void	print_node(t_node *new);
void	print_node_b(t_node *new, t_node *newb);
/**********************************************************/
/*                        NODES                           */
/**********************************************************/
t_node	*new_node(int content);
void	add_node_prev(t_node **head, t_node *new);
void	add_node_next(t_node **head, t_node *new);
t_node	*rem_node(t_node **r_node);

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
void	pb(t_data *data);
void	pa(t_data *data);


#endif