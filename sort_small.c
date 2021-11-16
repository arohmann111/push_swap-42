#include "push_swap.h"

void	sort_small(t_data *data, int ac)
{
	if (ac == 2)
		sort_two(data);
	else if (ac == 3)
		sort_three(data);
	else if (ac <= 5)
		sort_five(data, ac);
	return ;
}