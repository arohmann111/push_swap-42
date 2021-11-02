#include "push_swap.h"

t_node	*new_node(int content)
{
	t_node	*new;
	
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->num = content;
	new->prev = new;
	new->next = new;
	return (new);
}

void	add_node_back(t_node **head, t_node *new)
{
	if (*head != NULL)
	{
		(*head)->prev->next = new;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		new->next = *head;
	}
	else
		*head = new;
}

void	add_node_front(t_node **head, t_node *new)
{
	t_node	*last;

	if (*head != NULL)
	{
		(*head)->next->prev = new;
		new->next = (*head)->next;
		(*head)->next = new;
		new->prev = *head;
	}
	else
		*head = new;
}

void	print_node(t_node *new)
{
	printf(RED"prev: %p\n"RE, new->prev);
	printf(YELL"new:  %p\n"RE,  new);
	printf(GREEN"next: %p\n\n"RE, new->next);
} 

/* void	print_node(t_node *new, t_node *newb)
{
	printf(RED"prev: %p %p\n"RE, new->prev, newb->prev);
	printf(YELL"new:  %p %p\n"RE,  new, newb);
	printf(GREEN"next: %p %p\n\n"RE, new->next, newb->next);
} */

void	printb(t_data *data, t_node *new)
{
	t_node *item;
	int i;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack B\n"RE);
	if (data->head_b)
    {
        item = data->head_b;
        i = 0;

        while ((item->next != data->head_b && i < 10))
        {
            printf("%i\n", item->num);
            print_node(item);
            item = item->next;
            i++;
        }
        printf("%i\n", item->num);
        print_node(item);
    }
	else
	{
		printf(RED"Empty Stack !\n"RE);
	}
}

void	printa(t_data *data, t_node *new)
{
	t_node *item;
	int i;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack A\n"RE);
	if (data->head_a)
    {
        item = data->head_a;
        i = 0;

        while ((item->next != data->head_a && i < 10))
        {
            printf("%i\n", item->num);
            print_node(item);
            item = item->next;
            i++;
        }
        printf("%i\n", item->num);
        print_node(item);
    }
	else
	{
		printf(RED"Empty Stack !\n"RE);
	}
}

t_node	*rem_node(t_node **r_node)
{
	t_node *node;

	node = *r_node;
	if ((*r_node)->next == *r_node)
		*r_node = NULL;
	else
	{
		(*r_node)->prev->next = (*r_node)->next;
		(*r_node)->next->prev = (*r_node)->prev;
		*r_node = (*r_node)->next;
	}
	node->next = node;
	node->prev = node;
	return (node);
}

t_node	*init_head(t_node *head, int content)
{
	head = new_node(content);	
	head->next = head;
	head->prev = head;
	return(head);
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
	data->head_a = NULL;
	data->head_b = NULL;

	printa(data, new);
	while (av[i] != NULL)
	{
		new = new_node(ft_atoi(*(&av[i])));
		//printf("check\n");
		add_node_back(&data->head_a, new);
		printa(data, new);
		i++;
	}
	
	pb(data);
	printa(data, new);
	printb(data, new);
	pb(data);
	printa(data, new);
	printb(data, new);
	pb(data);
	printa(data, new);
	printb(data, new);
	pb(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	pa(data);
	printa(data, new);
	printb(data, new);
	//rra(data);
	//printa(data, new);
	//printf("Node:\n");
	//print_node(data->head_a);
	//input_check(ac, av);
	
}
