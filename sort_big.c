/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:57:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/25 17:49:54 by arohmann         ###   ########.fr       */
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
void	create_opti(t_data *data, t_opti *opti, int posa, int posb)
{
	opti->a_up = posa;
	opti->a_down = data->size_a - posa;
	opti->b_down = data->size_b - posb;
	opti->b_up = posb;

	opti->ad_bd = opti->a_down + opti->b_down;
	opti->ad_bu = opti->a_down + opti->b_up;
	opti->au_bu = opti->a_up + opti->b_up;
	opti->au_bd = opti->a_up + opti->b_down;
}

int		opti_opti(t_opti *opti)
{
	if (opti->ad_bd <= opti->ad_bu && opti->ad_bd <= opti->au_bu && opti->ad_bd <= opti->au_bd)
	{
		opti->mode = AD_BD;
		return (opti->ad_bd);
	}
	if (opti->ad_bu <= opti->ad_bd && opti->ad_bu <= opti->au_bu && opti->ad_bu <= opti->au_bd)
	{
		opti->mode = AD_BU;
		return (opti->ad_bu);
	}
	if (opti->au_bd <= opti->ad_bu && opti->au_bd <= opti->au_bu && opti->au_bd <= opti->ad_bd)
	{
		opti->mode = AU_BD;
		return (opti->au_bd);
	}
	else
	{
		opti->mode = AU_BU;
		return (opti->au_bu);
	}
}

void	opt_push(t_data *data)
{
	t_opti	opti;
	t_node	*head;
	int pos;
	int i;

	i = 0;
	head = data->head_b;
	data->best = data->size_a + data->size_b;
	while (i < data->size_b)
	{
		pos = find_pos_a(data, head);
		create_opti(data, &opti, pos, i);
		opti.opti = opti_opti(&opti);
		if (opti.opti < data->best)
		{	
			data->sort_m = opti.mode;
			data->best = opti.opti;
		}
		i++;
	}
	//solve_opti(data);
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
	//printf("s: %d\n", data->size_a);
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
