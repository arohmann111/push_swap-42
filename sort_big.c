/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:57:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/19 20:00:39 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**create_lis(t_data *data)
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
}

static int	*find_lis(t_data *data)
{
	int	**arr;
	int	i;
	int	j;
	int	k;

	arr = create_lis(data);
	k = 0;
	while (k < data->size_a)
	{				
		if (arr[0][0] > data->head_a->num || arr[0][0] == -1)
			arr[0][0] = data->head_a->num;
		else
		{
			i = 0;
			while (i < data->size_a && arr[i][i] != -1)
			{
				if (data->head_a->num > arr[i][i]
					&& (arr[i + 1][i + 1] > data->head_a->num || arr[i + 1][i + 1] == -1))
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
		}
		data->head_a = data->head_a->next;
		k++;
	}
	while (arr[i][i] != -1)
		i++;
	return (arr[i - 1]);
}

void	sort_big(t_data *data)
{
	int	**arr;
	int	i;
	int	j;

	arr = find_l_sequence(data);
	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j <= i)
		{
			printf("%d\t", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	/* a function wich sets a flag for staying in the A stack*/
	flag_lis(data, arr);
	
	ft_free_arr(arr);
}
