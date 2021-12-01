#include "push_swap.h"

static int	exec_acts(char *act, t_data *data)
{
	int	print;

	print = 0;
	if (!ft_strcmp(act, "sa"))
		sa(data, print);
	else if (!ft_strcmp(act, "sb"))
		sb(data, print);
	else if (!ft_strcmp(act, "ss"))
		ss(data, print);
	else if (!ft_strcmp(act, "ra"))
		ra(data, print);
	else if (!ft_strcmp(act, "rb"))
		rb(data, print);
	else if (!ft_strcmp(act, "rr"))
		rr(data, print);
	else if (!ft_strcmp(act, "rrr"))
		rrr(data, print);
	else if (!ft_strcmp(act, "rra"))
		rra(data, print);
	else if (!ft_strcmp(act, "rrb"))
		rrb(data, print);
	else if (!ft_strcmp(act, "pa"))
		pa(data, print);
	else if (!ft_strcmp(act, "pb"))
		pb(data, print);
	else
		return (1);
	return (0);
}

static int	read_acts(t_data *data)
{
	char	*line;
	while ((line = get_next_line(0) != NULL))
	{
		exec_acts(line, data);
	}
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
	printa(data);
	read_acts(data);
	printf("hi\n");
	if (is_sorted(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(data);
	return (0);
}
