/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:57:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/22 16:37:19 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	needs_pb(t_data *data)
{
	int	i;
	int size;

	i = 0;
	size = data->size_a;
	while (i < size + 1)
	{
		if (data->head_a->lis != 1)
			pb(data);
		ra(data);
		data->head_a = data->head_a->next;
		i++;
	}
}
int	find_pos_a(t_data *data, t_node *node)
{
	int i;
	t_node *head;

	i = 0;
	head = data->head_a;
	while (i < data->size_a)
	{
		if (head->num < node->num && head->next->num > node->num)
		{
			head = head->next;
			return (i + 1);
		}
		head = head->next;
		i++;
	}
	if (node->num < find_s_node(data->head_a, data->size_a))
		i = find_smallest(data->head_a, data->size_a);
	else if (node->num > find_l_node(data->head_a, data->size_a))
		i = find_biggest(data->head_a, data->size_a);
	return (i);
}

int	find_biggest(t_node *head, int size)
{
	int i;
	int pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num > val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (pos + 1);
}

void	push_pos_a(t_data *data, int pos)
{
	if (pos <= (data->size_a/ 2))
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
		pa(data);
	}
	else
	{
		while (pos < data->size_a)
		{
			rra(data);
			pos++;
		}
		pa(data);
	}
}

void	opt_push(t_data *data)
{
	int pos;

	while (data->size_b)
	{
		pos = find_pos_a(data, data->head_b);
		//printf("pos: %d\n", pos);
		push_pos_a(data, pos);
	}
}

void	sort_big(t_data *data)
{
	int	*arr;
	int	i;
	t_node *head;

	arr = find_lis(data);
	flag_lis(data, arr);
	needs_pb(data);
	opt_push(data);
	i = 0;
	head = data->head_a;
	while (i < data->size_a && data->head_a->num != find_s_node(data->head_a, data->size_a))
	{
		ra(data);
		head = head->next;
		i++;
	}
	printa(data);
	printb(data);
	//ft_free_arr(arr);
}
