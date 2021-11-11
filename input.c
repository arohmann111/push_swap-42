#include "push_swap.h"

void	check_int(char **av)
{
	int	i;
	int	error;
	int	error1;

	i = 0;
	error = 0;
	error1 = 0;
	while(av[i] != NULL)
	{
		if ((long)ft_atoi(av[i], &error) != ft_atol(av[i], &error1))
			exit (1);
		i++;
	}
	if (error != 0 || error1 != 0)
		exit (1);
}

void	check_dups(t_data *data)
{
	int i;
	int j;
	
	if (data->arr == NULL)
		exit (1);
	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			if (data->arr[i]  == data->arr[j] && i != j)
			{
				exit (1);
				printf("ERROR\n");
			}
			j++;
		}
		i++;
	}
}

void	count_args(int	ac, char **av, t_data *data)
{
	int		i;
	int		j;
	char	**tmp;

	if (ac < 2)
	{
		write(2, "Invalid amount of arguments!\n", 30);
		exit (1);
	}
	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if (tmp == NULL)
			exit (1);
		j = 0;
		while (tmp[j])
			j++;
		data->size += j;
		i++;
		free(tmp);
	}
}

void	parse_args(int ac, char **av, t_data *data)
{
	int		i;
	char	**tmp;
	int		j;
	int		error;

	error = 0;
	data->arr = (int *)malloc(sizeof(int) * data->size);
	if (data->arr == NULL)
		exit (1);
	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if (tmp == NULL)
			exit (1);
		j = 0;
		while (tmp[j])
		{
			data->arr[(i - 1) + j] = ft_atoi(tmp[j], &error);
			j++;
		}
		free (tmp);
		i++;
	}
}

void	check_input(int	ac, char **av, t_data *data)
{
	//check_errors(av);
	count_args(ac, av, data);
	parse_args(ac, av, data);
	check_dups(data);
}
