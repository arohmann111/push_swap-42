#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	tmp = data->head_b->num;
	data->head_b->num = data->head_b->next->num;
	data->head_b->next->num = tmp;
}