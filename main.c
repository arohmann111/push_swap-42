#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_node  *new;
	int i;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	i = 1;
	data->head_a = NULL;
	data->head_b = NULL;

	printa(data);
	printb(data);
	if (ac > 2)
	{
		while (av[i] != NULL)
		{
			new = new_node(ft_atoi(*(&av[i])));
			add_node_prev(&data->head_a, new);
			printb(data);
			printa(data);
			i++;
		}

		pb(data);
		printa(data);
		printb(data);
	}
	else 
		write(1,"No input!", 10);
}
