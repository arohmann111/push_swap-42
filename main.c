#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_node  *new;
	int i;
	int *error;

	error = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	i = 1;
	data->head_a = NULL;
	data->head_b = NULL;
	if (ac > 1)
	{
		printa(data);
		printb(data);

		while (av[i] != NULL)
		{
			input_check(ac, av);
			new = new_node((av[i]);
/* 			if (new == NULL)
				free_list_error(); */
			add_node_prev(&data->head_a, new);
			printa(data);
			printb(data);
			i++;
		}
		pb(data);
		printa(data);
		printb(data);
		pa(data);
		printa(data);
		printb(data);
	}
}
