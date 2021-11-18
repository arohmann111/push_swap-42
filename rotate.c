/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:41:23 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/18 14:29:51 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	data->head_a = data->head_a->next;
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	data->head_b = data->head_b->next;
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	data->head_a = data->head_a->next;
	data->head_b = data->head_b->next;
	write(1, "rr\n", 3);
}
