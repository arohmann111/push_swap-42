
void	print(t_data *data, t_node *new)
{
	t_node *item;
	t_node *itemb;
	int i;

	if (data->head_a || data->head_b )
    {
        item = data->head_a;
		itemb = data->head_b;
        i = 0;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack A							Stack B\n"RE);
        while ((item->next != data->head_a && i < 10)  || (itemb->next != data->head_b && i < 10) )
        {
            printf("%i							%i\n", item->num, itemb->num);
            print_node(item, itemb);
            item = item->next;
			itemb = itemb->next;
            i++;
        }
        printf("%i							%i\n", item->num, itemb->num);
        print_node(item, itemb);
    }
	else
	{
		printf("Empty Stack !");
	}
}

/* void	print(t_data *data, t_node *new)
{
	t_node *item;
	int i;

	if (data->head_a)
    {
        item = data->head_a;
        i = 0;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack A\n"RE);
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
		printf("Empty Stack !");
	}
} */