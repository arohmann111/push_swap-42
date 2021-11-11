#include "push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	return (data);
}
