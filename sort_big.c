#include "push_swap.h"

int	*find_l_sequence(t_data *data)
{
	int	**arr;
	int	num;
	int	i;
	int	j;

	arr = (int **)malloc(sizeof(int) * data->size_a);
	if (arr == NULL)
		return (NULL);

	i = 1;
	arr[0][0] = data->head_a->num;
	while (i < data->size_a - 1)
	{	
		j = 0;
		while (j < i)
		{
			if (data->head_a->num < data->head_a->next->num)
				arr[i][j] = num;
			j++;
		}
		data->head_a = data->head_a->next;
		i++;
	}

}
void	sort_big(t_data *data)
{
	find_l_sequence(data);
}