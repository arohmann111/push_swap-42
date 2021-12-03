/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:20:44 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:22:00 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ad_bd(t_data *data, t_opti *opti)
{
	while (opti->a_down > 0 && opti->b_down > 0)
	{
		rrr(data, 1);
		opti->a_down--;
		opti->b_down--;
	}
	while (opti->b_down > 0)
	{
		rrb(data, 1);
		opti->b_down--;
	}
	while (opti->a_down > 0)
	{
		rra(data, 1);
		opti->a_down--;
	}
	pa(data, 1);
}

void	sort_ad_bu(t_data *data, t_opti *opti)
{
	while (opti->a_down > 0)
	{
		rra(data, 1);
		opti->a_down--;
	}
	while (opti->b_up > 0)
	{
		rb(data, 1);
		opti->b_up--;
	}
	pa(data, 1);
}

void	sort_au_bd(t_data *data, t_opti *opti)
{
	while (opti->a_up > 0)
	{
		ra(data, 1);
		opti->a_up--;
	}
	while (opti->b_down > 0)
	{
		rrb(data, 1);
		opti->b_down--;
	}
	pa(data, 1);
}

void	sort_au_bu(t_data *data, t_opti *opti)
{
	while (opti->a_up > 0 && opti->b_up > 0)
	{
		rr(data, 1);
		opti->a_up--;
		opti->b_up--;
	}
	while (opti->b_up > 0)
	{
		rb(data, 1);
		opti->b_up--;
	}
	while (opti->a_up > 0)
	{
		ra(data, 1);
		opti->a_up--;
	}
	pa(data, 1);
}
