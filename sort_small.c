#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->head_a->num > data->head_a->next->num)
		sa(data);
	return ;
}

static void	sort_three(t_data *data)
{

	if (data->head_a->num > data->head_a->next->num && data->head_a->next->num > data->head_a->prev->num 
		&& data->head_a->prev->num < data->head_a->num)
		{
			sa (data);
			rra (data);
		}
	else if (data->head_a->num > data->head_a->next->num && data->head_a->next->num < data->head_a->prev->num 
		&& data->head_a->prev->num < data->head_a->num)
		{
			sa (data);
			ra (data);
		}
	else if (data->head_a->num > data->head_a->next->num && data->head_a->next->num < data->head_a->prev->num 
		&& data->head_a->prev->num > data->head_a->num)
			sa (data);
	else if (data->head_a->num < data->head_a->next->num && data->head_a->next->num > data->head_a->prev->num 
		&& data->head_a->prev->num < data->head_a->num)
			ra (data);
	else if (data->head_a->num < data->head_a->next->num && data->head_a->next->num > data->head_a->prev->num 
		&& data->head_a->prev->num > data->head_a->num)
			rra (data);

	return ;
}

void	sort_five(data)
{
	
}

void	sort_small(t_data *data)
{
	if (data->size == 2)
		sort_two(data);
	else if (data->size == 3)
		sort_three(data);
	else if (data->size <= 5)
		sort_five(data);
	return ;
}