#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	check_input(ac, av, data);
	create_stack_a(data);
	if (is_sorted(data) != 0)
	{
		if (data->size_a <= 5)
			sort_small(data);
		else
			sort_big(data);
	}
	return (0);
}
