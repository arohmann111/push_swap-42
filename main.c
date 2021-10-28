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

void	add_node_back(t_node *head_a, t_node *new)
{
	t_node	*last;

	if (head_a != NULL)
	{
		head_a->prev->next = new;
		new->prev = head_a->prev;
		head_a->prev = new;
		new->next = head_a;
	}
	// else
		// head_a = new;
}

void	print_node(t_node *new)
{
	printf(RED"prev: %p\n"RE, new->prev);
	printf(YELL"new:  %p\n"RE,  new);
	printf(GREEN"next: %p\n\n"RE, new->next);
}

void	print(t_node *head_a, t_node *new)
{
	t_node *item;
	int i;

	if (head_a)
    {
        item = head_a;
        i = 0;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack A \n"RE);
        while (item->next != head_a && i < 10)
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
	t_node *new;
	t_node *head_a;
	int		tmp;
	int i;

	i = 1;
	head_a = new_node(ft_atoi(*(&av[i++])));	
	head_a->next = head_a;
	head_a->prev = head_a;


	while (av[i] != NULL)
	{
		tmp = ft_atoi(*(&av[i])); //&av[1]
		new = new_node(tmp);
		add_node_back(head_a, new);
		print(head_a, new);
		i++;
	}

	//input_check(ac, av);
	
}
