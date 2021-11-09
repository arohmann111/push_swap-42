#include "push_swap.h"
int	get_index(t_data *data, int i)
{
	int	j;
	int	index;

	index = 0;
	j = 0;
	while (j < data->size)
	{
		if (data->arr[j] < data->arr[i])
			index++;
		j++;
	}
	return (index);
}

int	get_stack_a(t_data *data)
{
	//t_node	*new;
	int		i;

	i = 0;
	data->stack = (t_node *)malloc(sizeof(t_node)*data->size);
	if (data->stack == NULL)
		return (-1);
	while (i < data->size)
	{
		add_node_prev(&(data->head_a), &(data->stack[i]));
		data->stack[i].num = get_index(data, i);
		i++;
	}
	printa(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = init_data();
	parse_args(ac, av, data);
	get_stack_a(data);
	i = 0;
	while (i < data->size)
		printf("arr: %d\n", data->arr[i++]);
	printf("size: %d\n", data->size);

	i = 0;
	//error = 0;
/* 	if (ac > 1)
	{
		printa(data);
		printb(data);

		while (av[i] != NULL)
		{
			new = new_node(ft_atoi(av[i], &error));
			if (new == NULL)
				free_list_error();
			add_node_prev(&data->head_a, new);
			printa(data);
			printb(data);
			i++;
		}
	} */
	/* 	pb(data);
		printa(data);
		printb(data);
		pa(data);
		printa(data);
		printb(data); */
	return (0);
}
