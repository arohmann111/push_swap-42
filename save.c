static int	*find_lis(t_data *data)
{
	int	**arr;
	int	i;
	int	j;
	int	k;

	arr = create_lis_arr(data);
	k = 0;
	while (k < data->size_a)
	{				
		if (arr[0][0] > data->head_a->num || arr[0][0] == -1)
			arr[0][0] = data->head_a->num;
		else
		{
			i = 0;
			while (i < data->size_a && arr[i][i] != -1)
			{
				if (data->head_a->num > arr[i][i]
					&& (arr[i + 1][i + 1] > data->head_a->num || arr[i + 1][i + 1] == -1))
				{
					j = 0;
					while (j <= i)
					{
						arr[i + 1][j] = arr[i][j];
						j++;
					}
					arr[i + 1][j] = data->head_a->num;
				}
				i++;
			}
		}
		data->head_a = data->head_a->next;
		k++;
	}
	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j <= i)
		{
			printf("%d\t", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	//i = 0;
	//while (arr[i][i] != -1)
	//	i++;
	return (arr[i - 1]);
}