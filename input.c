/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:55 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:45:43 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_int(char **av, int ac)
{
	int	i;
	int	error;
	int	error1;

	i = 1;
	error = 0;
	error1 = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i], &error) != ft_atol(av[i], &error1))
			free_error(NULL, NULL, NULL);
		if (error != 0 || error1 != 0)
			free_error(NULL, NULL, NULL);
		i++;
	}
}

static void	check_dups(t_data *data)
{
	int	i;
	int	j;

	if (data->arr == NULL)
		exit (1);
	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j < data->size_a)
		{
			if (data->arr[i] == data->arr[j] && i != j)
				free_error(NULL, NULL, data->arr);
			j++;
		}
		i++;
	}
}

static void	count_args(int	ac, char **av, t_data *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if (tmp == NULL)
			free_error(NULL, NULL, NULL);
		j = 0;
		while (tmp[j])
			j++;
		data->size_a += j;
		i++;
		ft_free_split(&tmp);
	}
	if (data->size_a < 2)
		exit (1);
	data->arr = (int *)malloc(sizeof(int) * data->size_a);
	if (data->arr == NULL)
		free_error(NULL, NULL, data->arr);
}

static void	parse_args(char **av, t_data *data)
{
	int		i;
	char	**tmp;
	int		j;
	int		error;
	int		c;

	error = 0;
	c = 0;
	i = 1;
	while (av[i])
	{
		tmp = ft_split(av[i], ' ');
		if (tmp == NULL)
			free_error(NULL, NULL, data->arr);
		j = 0;
		while (tmp[j])
		{
			data->arr[c] = ft_atoi(tmp[j], &error);
			j++;
			c++;
		}
		ft_free_split(&tmp);
		i++;
	}
}

void	check_input(int	ac, char **av, t_data *data)
{
	check_int(av, ac);
	count_args(ac, av, data);
	parse_args(av, data);
	check_dups(data);
}
