/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_in_seq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:47:10 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:48:57 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**create_lis_arr(t_data *data)
{
	int	**arr;
	int	i;
	int	j;

	arr = (int **)malloc(sizeof(int *) * data->size_a);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < data->size_a)
	{
		arr[i] = (int *)malloc(sizeof(int) * (i + 1));
		i++;
	}
	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j <= i)
		{
			arr[i][j] = -1;
			j++;
		}
		i++;
	}
	return (arr);
}

static int	**make_lis(t_data *data, int **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a && (arr[i][i] != -1))
	{
		if (data->head_a->num > arr[i][i]
			&& (arr[i + 1][i + 1] > data->head_a->num
			|| arr[i + 1][i + 1] == -1))
		{
			j = 0;
			while (j <= i)
			{
				arr[i + 1][j] = arr[i][j];
				j++;
			}
			arr[i + 1][j] = data->head_a->num;
		}
		i++;
	}
	return (arr);
}

int	*find_lis(t_data *data)
{
	int	**arr;
	int	i;
	int	k;

	arr = create_lis_arr(data);
	k = 0;
	while (k < data->size_a)
	{				
		if (arr[0][0] > data->head_a->num || arr[0][0] == -1)
			arr[0][0] = data->head_a->num;
		else
		{
			arr = make_lis(data, arr);
		}
		data->head_a = data->head_a->next;
		k++;
	}
	i = 0;
	while (arr[i][i] != -1)
		i++;
	data->lis_l = i;
	return (arr[i - 1]);
}

void	flag_lis(t_data *data, int *arr)
{
	int		i;
	int		j;
	t_node	*head;

	i = 0;
	head = data->head_a;
	while (i < data->size_a)
	{
		j = 0;
		while (j < data->lis_l)
		{
			if (head->num == arr[j])
			{
				head->lis = 1;
				break ;
			}
			j++;
		}
		head = head->next;
		i++;
	}
}
