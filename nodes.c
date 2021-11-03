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

void	add_node_prev(t_node **head, t_node *new)
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

void	add_node_next(t_node **head, t_node *new)
{
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