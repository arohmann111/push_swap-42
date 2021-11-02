#include "push_swap.h"

void	pb(t_data *data)
{
	t_node *r_node;

	r_node = rem_node(&data->head_a);
	add_node_back(&data->head_b, r_node);
	data->head_b = data->head_b->prev;
}