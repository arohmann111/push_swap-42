/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:57:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/26 15:16:27 by arohmann         ###   ########.fr       */
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

void	rotate_to_0(t_data *data, int pos)
{
	if (pos <= (data->size_a / 2))
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
	}
	else
	{
		while (pos < data->size_a)
		{
			rra(data);
			pos++;
		}
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
void	sort_ad_bd(t_data *data, t_opti *opti)
{
	while (opti->a_down > 0 && opti->b_down > 0)
	{
		rrr(data);
		opti->a_down--;
		opti->b_down--;
	}
	while (opti->b_down > 0)
	{
		rrb(data);
		opti->b_down--;
	}
	while (opti->a_down > 0)
	{
		rra(data);
		opti->a_down--;
	}
	pa(data);
}

void	sort_ad_bu(t_data *data, t_opti  *opti)
{
	while (opti->a_down > 0)
	{
		rra(data);
		opti->a_down--;
	}
	while (opti->b_up > 0)
	{
		rb(data);
		opti->b_up--;
	}
	pa(data);
}

void	sort_au_bd(t_data *data, t_opti *opti)
{
	while (opti->a_up > 0)
	{
		ra(data);
		opti->a_up--;
	}
	while (opti->b_down > 0)
	{
		rrb(data);
		opti->b_down--;
	}
	pa(data);
}
void	sort_au_bu(t_data *data, t_opti *opti)
{
	while (opti->a_up > 0 && opti->b_up > 0)
	{
		rr(data);
		opti->a_up--;
		opti->b_up--;
	}
	while (opti->b_up > 0)
	{
		rb(data);
		opti->b_up--;
	}
	while (opti->a_up > 0)
	{
		ra(data);
		opti->a_up--;
	}
	pa(data);
}

void	solve_opti(t_data *data, t_opti *opti)
{
	create_opti(data, opti, data->best_a, data->best_b);
/* 	printf("ad: %d\n", opti->a_down);
	printf("au: %d\n", opti->a_up);
	printf("bd: %d\n", opti->b_down);
	printf("bu: %d\n\n\n", opti->b_up); */
	if (data->sort_m == AD_BD)
		sort_ad_bd(data, opti);
	else if (data->sort_m == AD_BU)
		sort_ad_bu(data, opti);
	else if (data->sort_m == AU_BD)
		sort_au_bd(data, opti);
	else if (data->sort_m == AU_BU)
		sort_au_bu(data, opti);
	return ;
}

void	opt_push(t_data *data)
{
	t_opti	opti;
	t_node	*head;
	int pos;
	int i;

	while (data->head_b)
	{
		head = data->head_b;
		data->best = data->size_a + data->size_b;
		i = 0;
		while (i < data->size_b)
		{
			pos = find_pos_a(data, head);
			create_opti(data, &opti, pos, i);
			opti.opti = opti_opti(&opti);
			if (opti.opti < data->best)
			{	
				//printf("####################hez\n");
				data->sort_m = opti.mode;
				data->best = opti.opti;
				data->best_a = pos;
				data->best_b = i;
				data->best_n = head->num;
			}
			head = head->next;
			i++;
		}
/* 		printf("mode: %d\n", data->sort_m);
		printf("b_num: %d\n", data->best_n); */
/* 		printf("num: %d\n", head->num);
		printf("b: %d\n", data->best);
		printf("ba: %d\n", data->best_a);
		printf("bb: %d\n\n\n", data->best_b); */
/* 		printa(data);
		printb(data); */
		solve_opti(data, &opti);
	}
	//printf("s: %d", data->size_b);
	return ;
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
	int	pos;
	
	arr = find_lis(data);
	flag_lis(data, arr);
	if (data->lis_l > 1)
		needs_pb(data);
	else
		solve_rev(data);
	opt_push(data);
	pos = find_smallest(data->head_a, data->size_a);
	rotate_to_0(data, pos);
	//printa(data);
	//printb(data);
	exit(0);
	//ft_free_arr(arr);
}
