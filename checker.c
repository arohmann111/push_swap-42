/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:40:28 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 14:58:36 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_acts(char *act, t_data *data)
{
	if (!ft_strcmp(act, "sa\n"))
		sa(data, 0);
	else if (ft_strcmp(act, "sb\n") == 0)
		sb(data, 0);
	else if (ft_strcmp(act, "ss\n") == 0)
		ss(data, 0);
	else if (ft_strcmp(act, "ra\n") == 0)
		ra(data, 0);
	else if (ft_strcmp(act, "rb\n") == 0)
		rb(data, 0);
	else if (ft_strcmp(act, "rr\n") == 0)
		rr(data, 0);
	else if (ft_strcmp(act, "rrr\n") == 0)
		rrr(data, 0);
	else if (ft_strcmp(act, "rra\n") == 0)
		rra(data, 0);
	else if (ft_strcmp(act, "rrb\n") == 0)
		rrb(data, 0);
	else if (ft_strcmp(act, "pa\n") == 0)
		pa(data, 0);
	else if (ft_strcmp(act, "pb\n") == 0)
		pb(data, 0);
	else
		free_error(data->head_a, data->head_b, data->arr);
	return (0);
}

static int	read_acts(t_data *data)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		exec_acts(line, data);
		free(line);
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	if (ac < 2)
		return (1);
	check_input(ac, av, data);
	create_stack_a(data);
	read_acts(data);
	if (is_sorted(data) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(data);
	return (0);
}
