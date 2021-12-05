/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:50:01 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:50:03 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		*head = new;
		new->prev = new;
		new->next = new;
	}
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
	{
		*head = new;
		new->prev = new;
		new->next = new;
	}
}

t_node	*rem_node(t_node **r_node)
{
	t_node	*node;

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
