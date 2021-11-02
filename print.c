/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:45:46 by arohmann          #+#    #+#             */
/*   Updated: 2021/11/02 17:00:48 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_data *data, t_node *new)
{
	t_node *item;
	t_node *itemb;
	int i;

	if (data->head_a->next  || data->head_b )
    {
        item = data->head_a;
		//itemb = data->head_b;
        i = 0;
        printf(CYAN"%s", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("Stack A							Stack B\n"RE);
        while ((item->next != data->head_a && i < 10)  || (itemb->next != data->head_b && i < 10) )
        {
            printf("%i							%i\n", item->num, itemb->num);
            print_node_b(item, itemb);
            item = item->next;
			itemb = itemb->next;
            i++;
        }
        printf("%i							%i\n", item->num, itemb->num);
        print_node_b(item, itemb);
    }
	else
	{
		printf(RED"Empty Stack !\n"RE);
	}
}

void	print_node(t_node *new)
{
	printf(RED"prev: %p\n"RE, new->prev);
	printf(YELL"new:  %p\n"RE,  new);
	printf(GREEN"next: %p\n\n"RE, new->next);
} 

void	print_node_b(t_node *new, t_node *newb)
{
	printf(RED"prev: %p					%p\n"RE, new->prev, newb->prev);
	printf(YELL"new:  %p					%p\n"RE,  new, newb);
	printf(GREEN"next: %p					%p\n\n"RE, new->next, newb->next);
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