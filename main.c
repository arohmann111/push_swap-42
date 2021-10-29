#include "push_swap.h"

t_node	*new_node(int content)
{
	t_node	*new;
	
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->num = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_node_back(t_data *data, t_node *new)
{
	t_node	*last;

	if (data->head_a != NULL)
	{
		data->head_a->prev->next = new;
		new->prev = data->head_a->prev;
		data->head_a->prev = new;
		new->next = data->head_a;
	}
	else
		data->head_a = new;
}


void	print_node(t_node *new)
{
	printf(RED"prev: %p\n"RE, new->prev);
	printf(YELL"new:  %p\n"RE,  new);
	printf(GREEN"next: %p\n\n"RE, new->next);
}

void	print(t_data *data, t_node *new)
{
	t_node *item;
	int i;

	if (data->head_a)
    {
        item = data->head_a;
        i = 0;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack A \n"RE);
        while (item->next != data->head_a && i < 10)
        {
            printf("%i\n", item->num);
            print_node(item);
            item = item->next;
            i++;
        }
        printf("%i \n", item->num);
        print_node(item);
    }
	else
	{
		printf("Empty Stack !");
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_node  *new;
	int		tmp;
	int i;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	i = 1;
	data->head_a = new_node(ft_atoi(*(&av[i++])));	
	data->head_a->next = data->head_a;
	data->head_a->prev = data->head_a;


	while (av[i] != NULL)
	{
		tmp = ft_atoi(*(&av[i])); //&av[1]
		new = new_node(tmp);
		add_node_back(data, new);
		print(data, new);
		i++;
	}
	sa(data);
	print(data, new);
	rra(data);
	print(data, new);
	//input_check(ac, av);
	
}
