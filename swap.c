/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:40:03 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/18 14:30:04 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	tmp = data->head_a->num;
	data->head_a->num = data->head_a->next->num;
	data->head_a->next->num = tmp;
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_data *data)
{
	int	tmp;

	tmp = data->head_b->num;
	data->head_b->num = data->head_b->next->num;
	data->head_b->next->num = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	int	tmp;

	tmp = data->head_a->num;
	data->head_a->num = data->head_a->next->num;
	data->head_a->next->num = tmp;
	tmp = data->head_b->num;
	data->head_b->num = data->head_b->next->num;
	data->head_b->next->num = tmp;
	write(1, "ss\n", 3);
}
