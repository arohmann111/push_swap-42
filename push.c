/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:19:36 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/02 16:19:40 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_node *r_node;

	r_node = rem_node(&data->head_b);
	add_node_prev(&data->head_a, r_node);
	data->head_a = data->head_a->prev;
}

void	pb(t_data *data)
{
	t_node *r_node;

	r_node = rem_node(&data->head_a);
	add_node_prev(&data->head_b, r_node);
	data->head_b = data->head_b->prev;
}
