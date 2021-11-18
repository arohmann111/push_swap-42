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

	i = 0;
	num = data->head_a->num;
	arr[0] = num;
	while (i < data->size_a)
	{	
		j = 0;
		while (j < i)
		{
			if (num < data->head_a->next->num && )
			arr[i][j] = num;
			j++;
		}
		i++;
	}

}
void	sort_big(t_data *data)
{
	find_l_sequence(data);
}