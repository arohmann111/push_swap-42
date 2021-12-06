/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:49:19 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:49:21 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	check_input(ac, av, data);
	create_stack_a(data);
	if (is_sorted(data) != 0)
	{
		if (data->size_a <= 5)
			sort_small(data);
		else
			sort_big(data);
	}
	return (0);
}
