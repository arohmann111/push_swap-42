/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:57:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/25 16:23:13 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	needs_pb(t_data *data)
{
	int	i;
	int size;

	i = 0;
	size = data->size_a;
	while (i < size)
	{
		if (data->head_a->lis == 0)
			pb(data);
		else
			ra(data);
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

void	push_pos_a(t_data *data, int pos)
{
	if (pos <= (data->size_a / 2))
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
		push_pos_a(data, pos);
	}
}

void	solve_rev(t_data *data)
{
	int i;
	int size;

	i = 0;
	size = data->size_a;
	while (i < size - 1)
	{	
		rra(data);
		pb(data);
		data->head_a = data->head_a->next;
		i++;
	}
	rrb(data);
	while (i < size + 1)
	{
		pa(data);
		data->head_b = data->head_b->next;
		i++;
	}
}

void	sort_big(t_data *data)
{
	int	*arr;
	int	i;
	t_node *head;

	arr = find_lis(data);
	flag_lis(data, arr);
	if (data->lis_l > 1)
		needs_pb(data);
	else
		solve_rev(data);
	opt_push(data);
	i = 0;
	head = data->head_a;
	while (i < data->size_a && data->head_a->num != find_s_node(data->head_a, data->size_a))
	{
		ra(data);
		head = head->next;
		i++;
	}
	//ft_free_arr(arr);
}
