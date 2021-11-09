#include "push_swap.h"


/* int		main(int ac, char **av)
{
	int	f;
	t_data	*data;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	data->head_a = NULL;
	data->head_b = NULL;
	data->size = 0;

	if (ac < 2)
	{
		write(2, "Not enough arguments!\n", 23);
		return (1);
	}
	else
	{
		if (ac == 2)
			f = 0;
		else
			f = 1;
		input(ac, av, data);
		write(1,"Nice\n", 6);
		printf("%d\n", data->arr[1]);
	}
	return (0);
} */
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
int	count_args(int	ac, char **av, t_data *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	if (ac < 2)
	{
		write(2, "Invalid amount of arguments!\n", 30);
		return (1);
	}
	else
	{
		while (av[i] != NULL)
		{
			printf("%s\n", av[i]);
			i++;
		}
		i = 1;
		while(i < ac)
		{
			tmp = ft_split(av[i], ' ');
			if (tmp == NULL)
				return (1);
			j = 0;
			while (tmp[j])
				j++;
			data->size += j;
			i++;
		}
	}
	return (0);
}
int	parse_args(int ac, char **av, t_data *data)
{
	int	i;
	char	**tmp;
	int		j;
	int		error;

	error = 0;
	count_args(ac, av, data);
	data->arr = (int *)malloc(sizeof(int) * data->size);
	if (data->arr == NULL)
		return (1);
	i = 1;

	while (i < ac)
	{
			tmp = ft_split(av[i], ' ');
			if (tmp == NULL)
				return (1);
			j = 0;
			while (tmp[j])
			{
				data->arr[j] = ft_atoi(tmp[j], &error);
				j++;
			}
			i++;
	}
	printf("ARR:\n%d\n", data->arr[0]);
	printf("%d\n", data->arr[1]);
	printf("%d\n", data->arr[2]);
	printf("%d\n", data->arr[3]);
	printf("%d\n", data->arr[5]);
	printf("J: %d\n", j);
	printf("%d\n", data->size);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	//t_node  *new;

	data = init_data();
	parse_args(ac, av, data);
	return (0);
	/* 	if (ac > 1)
	{
		printa(data);
		printb(data);

		while (av[i] != NULL)
		{
			input_check(ac, av);
			
			new = new_node(av[i]);
			if (new == NULL)
				free_list_error();
			add_node_prev(&data->head_a, new);
			printa(data);
			printb(data);
			i++;
		} */
	/* 	pb(data);
		printa(data);
		printb(data);
		pa(data);
		printa(data);
		printb(data); */

}
