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

void	create_stack_a(t_data *data)
{  
	int		i;

	i = 0;
	data->stack = (t_node *)malloc(sizeof(t_node)*data->size);
	if (data->stack == NULL)
		exit (1);
	while (i < data->size)
	{
		add_node_prev(&(data->head_a), &(data->stack[i]));
		data->stack[i].num = get_index(data, i);
		i++;
	}
	printa(data);
}

void	free_error(t_node *head_a, t_node *head_b, int *arr)
{
	if (head_a != NULL)
		free (head_a);
	if (head_b != NULL)
		free (head_b);
	if (arr != NULL)
		free (arr);
	write(2, "Error\n", 7);
	exit (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = init_data();
	check_input(ac, av, data);
	create_stack_a(data);
	i = 0;
	while (i < data->size)
		printf("arr: %d\n", data->arr[i++]);
	printf("size: %d\n", data->size);
/* 	pb(data);
	printa(data);
	printb(data);
	pa(data);
	printa(data);
	printb(data); */
	return (0);
}
