#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->head_a->num > data->head_a->next->num)
		sa(data);
	return ;
}

static	void sort_three(t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = data->head_a->num;
	two = data->head_a->next->num;
	three  = data->head_a->prev->num;
	if (one > two && two < three && three > one)
		sa(data);
	if (one > two && two > three && three < one)
	{
		sa(data);
		rra(data);
	}
	if (one > two && two < three && three < one)
		ra(data);
	if (one < two && two > three && three > one)
	{
		sa(data);
		ra(data);
	}
	if (one < two && two > three && three < one)
		rra(data);
}

static void	sort_five(t_data *data)
{
	int	size;
	int s_pos;

	size = data->size_a;
	while (size > 3)
	{
		s_pos = find_smallest(data->head_a, data->size_a);
		push_smallest(data, s_pos);
		size--;
	}
	sort_three(data);
	while(data->head_b)
		pa(data);
	return ;
}

void	push_smallest(t_data *data, int pos)
{
	if (pos <= (data->size_a/ 2))
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
		pb(data);
	}
	else
	{
		while (pos < data->size_a)
		{
			rra(data);
			pos++;
		}
		pb(data);
	}
}

int	find_smallest(t_node *head, int size)
{
	int i;
	int pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num < val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (pos);
}

int	find_s_node(t_node *head, int size)
{
	int i;
	int pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num < val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (val);
}

int	find_l_node(t_node *head, int size)
{
	int i;
	int pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num > val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (val);
}

void	sort_small(t_data *data)
{
	if (data->size_a == 2)
		sort_two(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_five(data);
	exit (1);
}