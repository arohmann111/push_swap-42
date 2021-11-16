/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:40:03 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/16 15:03:13 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	tmp = data->head_a->num;
	data->head_a->num = data->head_a->next->num;
	data->head_a->next->num = tmp;
	write(1, "sa\n", 4);
	return ;
}

void	sb(t_data *data)
{
	int	tmp;

	tmp = data->head_b->num;
	data->head_b->num = data->head_b->next->num;
	data->head_b->next->num = tmp;
	write(1, "sb\n", 4);
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
	write(1, "ss\n", 4);
}
