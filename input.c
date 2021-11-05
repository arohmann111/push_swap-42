#include "push_swap.h"

int	input_check(int ac, char **av)
{
	int i;
	int *error;
	int *error1;

	i = 0;
	while(av[i] != NULL)
	{
		if ((long)ft_atoi(av[i], error) != ft_atol(av[i], error1))
			return (0);
		i++;
	}
	return (1);
}