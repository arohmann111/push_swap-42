#include "push_swap.h"

int	count_args(int	ac, char **av, t_data *data)
{
	int		i;
	int		j;
	char	**tmp;

	if (ac < 2)
	{
		write(2, "Invalid amount of arguments!\n", 30);
		return (1);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			tmp = ft_split(av[i], ' ');
			if (tmp == NULL)
				return (1);
			j = 0;
			while (tmp[j])
				j++;
			data->size += j;
			i++;
			free(tmp);
		}
	}
	return (0);
}

int	parse_args(int ac, char **av, t_data *data)
{
	int		i;
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
			data->arr[(i - 1) + j] = ft_atoi(tmp[j], &error);
			j++;
		}
		i++;
	}
	return (0);
}

/*int	size(int *n)
{
	int i;

	i = 0;
	if (n == NULL)
		return (-1);
	while (n[i] != 0)
		i++;
	return (i);
}

int	input(int ac, char **av, t_data *data)
{
	int		i;
	int		error;
	char	**tmp;

	i = 1;

	error = 1;
	while (av[i++])
	data->size++;
	data->arr = (int *)malloc(sizeof(int)*data->size);
	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if(tmp == NULL)
			write(2, "ERROR\n", 7);  //free_all()
		if (ft_atoi(tmp[i], &error) != ft_atol(tmp[i], &error))
		{
			write(1, "Error", 6);
			free(data->arr);
			return (1);
		}
		else
			data->arr[i - 1] = ft_atoi(av[i], &error);
		i++;
	}
	return (0);
} */
/* 			while (j >= 0)
			{
				arr[t] = ft_atoi(tmp[t], &error);
				j--;
			} */
/* int	input_check(int ac, char **av)
{
	int i;
	int *error;
	int *error1;

	i = 0;
	error = 
	while(av[i] != NULL)
	{
		if ((long)ft_atoi(av[i], error) != ft_atol(av[i], error1))
			return (0);
		i++;
	}
	return (1);
} */