/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:42:28 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/01 15:32:11 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, int print)
{
	data->head_a = data->head_a->prev;
	if (print != 0)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int print)
{
	data->head_b = data->head_b->prev;
	if (print != 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data, int print)
{
	data->head_a = data->head_a->prev;
	data->head_b = data->head_b->prev;
	if (print != 0)
		write(1, "rrr\n", 4);
}
