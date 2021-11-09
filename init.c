#include "push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->head_a = NULL;
	data->head_b = NULL;
	data->size = 0;
	return (data);
}
