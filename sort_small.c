#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->head_a->num > data->head_a->next->num)
		sa(data);
	return ;
}

static void	sort_three(t_data *data)
{

	if (data->head_a->num > data->head_a->next->num && data->head_a->next->num > data->head_a->prev->num 
		&& data->head_a->prev->num < data->head_a->num)
		{
			sa (data);
			rra (data);
		}
	else if (data->head_a->num > data->head_a->next->num && data->head_a->next->num < data->head_a->prev->num 
		&& data->head_a->prev->num < data->head_a->num)
		{
			sa (data);
			ra (data);
		}
	else if (data->head_a->num > data->head_a->next->num && data->head_a->next->num < data->head_a->prev->num 
		&& data->head_a->prev->num > data->head_a->num)
			sa (data);
	else if (data->head_a->num < data->head_a->next->num && data->head_a->next->num > data->head_a->prev->num 
		&& data->head_a->prev->num < data->head_a->num)
			ra (data);
	else if (data->head_a->num < data->head_a->next->num && data->head_a->next->num > data->head_a->prev->num 
		&& data->head_a->prev->num > data->head_a->num)
			rra (data);

	return ;
}

static void	sort_five(t_data *data)
{
	int	size;
	int s_pos;

	size = data->size;
	while (size > 3)
	{
		s_pos = find_smallest(data->head_a);
		//printf("%d\n", s_pos);
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
	int	tmp;

	tmp = data->size;
	if (pos > (tmp / 2))
	{
		while (pos <= tmp)
		{
			rra(data);
			pos++;
		}
		pb(data);
	}
	else
	{
		while (pos > 1)
		{
			ra(data);
			pos--;
		}
		pb(data);
	}
  	printa(data);
	printb(data);
}

int		find_smallest(t_node *head)
{
	t_node *tmp;
	int		pos;
	int		val;
	int		i;

	i = 1;
	pos = 0;
	val = head->num;
	tmp = head;
	while (tmp->next != head)
	{
		if (val > tmp->num)
		{
			val = tmp->num;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	sort_small(t_data *data)
{
	if (data->size == 2)
		sort_two(data);
	else if (data->size == 3)
		sort_three(data);
	else if (data->size <= 5)
		sort_five(data);
	exit (1);
}