/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:18:45 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:23:43 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	opti_opti(t_opti *opti)
{
	if (opti->ad_bd <= opti->ad_bu && opti->ad_bd <= opti->au_bu
		&& opti->ad_bd <= opti->au_bd)
	{
		opti->mode = AD_BD;
		return (opti->ad_bd);
	}
	if (opti->ad_bu <= opti->ad_bd && opti->ad_bu <= opti->au_bu
		&& opti->ad_bu <= opti->au_bd)
	{
		opti->mode = AD_BU;
		return (opti->ad_bu);
	}
	if (opti->au_bd <= opti->ad_bu && opti->au_bd <= opti->au_bu
		&& opti->au_bd <= opti->ad_bd)
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

void	solve_opti(t_data *data, t_opti *opti)
{
	create_opti(data, opti, data->best_a, data->best_b);
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
