/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:42:28 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/02 13:42:30 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	data->head_a = data->head_a->prev;
}

void	rrb(t_data *data)
{
	data->head_b = data->head_b->prev;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
