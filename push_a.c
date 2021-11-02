#include "push_swap.h"

void	pa(t_data *data)
{
	t_node *r_node;

	r_node = rem_node(&data->head_b);
	add_node_back(&data->head_a, r_node);
	data->head_a = data->head_a->prev;
}