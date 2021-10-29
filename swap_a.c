#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	tmp = data->head_a->num;
	data->head_a->num = data->head_a->next->num;
	data->head_a->next->num = tmp;
}