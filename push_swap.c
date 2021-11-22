#include "push_swap.h"
int	get_index(t_data *data, int i)
{
	int	j;
	int	index;

	index = 0;
	j = 0;
	while (j < data->size_a)
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
	data->stack = (t_node *)malloc(sizeof(t_node)*data->size_a);
	if (data->stack == NULL)
		exit (1);
	while (i < data->size_a)
	{
		add_node_prev(&(data->head_a), &(data->stack[i]));
		data->stack[i].num = get_index(data, i);
		i++;
	}
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

int	is_sorted(t_data *data)
{
	t_node *tmp;
	int	i;

	i = 0;
	tmp = data->head_a;
	while (i < data->size_a)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	check_input(ac, av, data);
	create_stack_a(data);
	printa(data);
	if (is_sorted(data) != 0)
	{
		if (data->size_a <= 5)
			sort_small(data);
		else
			sort_big(data);
	}
	//printa(data);
	return (0);
}
