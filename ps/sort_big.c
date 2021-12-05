/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:57:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:26:21 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	needs_pb(t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = data->size_a;
	while (i < size)
	{
		if (data->head_a->lis == 0)
			pb(data, 1);
		else
			ra(data, 1);
		i++;
	}
}

int	find_pos_a(t_data *data, t_node *node)
{
	int		i;
	t_node	*head;

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

void	rotate_to_0(t_data *data, int pos)
{
	if (pos <= (data->size_a / 2))
	{
		while (pos > 0)
		{
			ra(data, 1);
			pos--;
		}
	}
	else
	{
		while (pos < data->size_a)
		{
			rra(data, 1);
			pos++;
		}
	}
}

void	opt_push(t_data *data)
{
	t_opti	opti;
	t_node	*head;
	int		pos;
	int		i;

	i = 0;
	head = data->head_b;
	while (i < data->size_b)
	{
		pos = find_pos_a(data, head);
		create_opti(data, &opti, pos, i);
		opti.opti = opti_opti(&opti);
		if (opti.opti < data->best)
		{	
			data->sort_m = opti.mode;
			data->best = opti.opti;
			data->best_a = pos;
			data->best_b = i;
			data->best_n = head->num;
		}
		head = head->next;
		i++;
	}
	solve_opti(data, &opti);
	return ;
}

void	sort_big(t_data *data)
{
	int	*arr;
	int	pos;

	arr = find_lis(data);
	flag_lis(data, arr);
	needs_pb(data);
	while (data->head_b)
	{
		data->best = data->size_a + data->size_b;
		opt_push(data);
	}
	pos = find_smallest(data->head_a, data->size_a);
	rotate_to_0(data, pos);
	system("leaks push_swap");
	exit(0);
}
