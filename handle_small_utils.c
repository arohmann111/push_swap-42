/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:26:15 by hskowron          #+#    #+#             */
/*   Updated: 2021/11/12 15:19:37 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lowest(t_data *data, int argc, int loc)
{
	if (loc > (argc / 2))
	{
		while (loc <= argc)
		{
			rra(data);
			loc++;
		}
		pb(data);
	}
	else
	{
		while (loc > 1)
		{
			ra(data);
			loc--;
		}
		pb(data);
	}
}
