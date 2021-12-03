/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:05:28 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:07:20 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->head_a->num > data->head_a->next->num)
		sa(data, 1);
	return ;
}

static void	sort_three(t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = data->head_a->num;
	two = data->head_a->next->num;
	three = data->head_a->prev->num;
	if (one > two && two < three && three > one)
		sa(data, 1);
	if (one > two && two > three && three < one)
	{
		sa(data, 1);
		rra(data, 1);
	}
	if (one > two && two < three && three < one)
		ra(data, 1);
	if (one < two && two > three && three > one)
	{
		sa(data, 1);
		ra(data, 1);
	}
	if (one < two && two > three && three < one)
		rra(data, 1);
}

static void	sort_five(t_data *data)
{
	int	size;
	int	s_pos;

	size = data->size_a;
	while (size > 3)
	{
		s_pos = find_smallest(data->head_a, data->size_a);
		push_smallest(data, s_pos);
		size--;
	}
	sort_three(data);
	while (data->head_b)
		pa(data, 1);
	return ;
}

void	push_smallest(t_data *data, int pos)
{
	if (pos <= (data->size_a / 2))
	{
		while (pos > 0)
		{
			ra(data, 1);
			pos--;
		}
		pb(data, 1);
	}
	else
	{
		while (pos < data->size_a)
		{
			rra(data, 1);
			pos++;
		}
		pb(data, 1);
	}
}

void	sort_small(t_data *data)
{
	if (data->size_a == 2)
		sort_two(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_five(data);
	exit (1);
}
