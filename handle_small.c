/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:30:24 by hskowron          #+#    #+#             */
/*   Updated: 2021/11/12 14:42:01 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_small_stack(t_data *data, int argc)
{
	if (argc == 2)
		handle_2(data);
	else if (argc == 3)
		handle_3(data);
	else if (argc <= 5)
		handle_4_5(data, argc);
	return ;
}

void	handle_2(t_data *data)
{
	if (data->istack_a->content > data->istack_a->next->content)
		sa(data);
	return ;
}

void	handle_3(t_data *data)
{
	int	first;
	int	second;
	int	third;

	while (1)
	{
		first = data->istack_a->content;
		second = data->istack_a->next->content;
		third = data->istack_a->next->next->content;
		if ((first > second && first < third)
			|| (first > second && second > third))
			sa(data);
		else if ((first < third && third < second)
			|| (third < first && first < second))
			rra(data);
		else if (first > second && third > second)
			ra(data);
		if (check_sorted(data) == 0)
			return ;
	}
}

void	handle_4_5(t_data *data, int argc)
{
	int	loc;

	while (argc > 3)
	{
		loc = find_lowest_loc_a(data);
		push_lowest(data, argc, loc);
		argc--;
	}
	handle_3(data);
	while (data->istack_b)
		pa(data);
	return ;
}

int	find_lowest_loc_a(t_data *data)
{
	int		x;
	int		value;
	int		loc;
	t_list	*tmp;

	loc = 0;
	x = 1;
	value = data->istack_a->content;
	tmp = data->istack_a;
	while (tmp)
	{
		if (value > tmp->content)
		{
			value = tmp->content;
			loc = x;
		}
		tmp = tmp->next;
		x++;
	}
	return (loc);
}
