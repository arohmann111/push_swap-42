/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:45 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:41:47 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	return (data);
}
