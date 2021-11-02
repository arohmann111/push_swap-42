/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:41:23 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/02 13:41:25 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	data->head_a = data->head_a->next;
}

void	rb(t_data *data)
{
	data->head_b = data->head_b->next;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
