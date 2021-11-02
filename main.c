#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_node  *new;
	int		tmp;
	int i;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	i = 1;
	data->head_a = NULL;
	data->head_b = NULL;

	printa(data, new);
	printb(data, new);
	while (av[i] != NULL)
	{
		new = new_node(ft_atoi(*(&av[i])));
		add_node_prev(&data->head_a, new);
		printb(data, new);
		printa(data, new);
		i++;
	}
	
	pb(data);
	printa(data, new);
	printb(data, new);
	pb(data);
	printa(data, new);
	printb(data, new);
	pb(data);
	printa(data, new);
	printb(data, new);
	pb(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	rra(data);
	printa(data, new);
	printb(data, new);
	sa(data);
	printa(data, new);
	printb(data, new);
}
