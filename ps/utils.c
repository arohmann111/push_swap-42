/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:05:12 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:05:15 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_node *head, int size)
{
	int	i;
	int	pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num > val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (pos + 1);
}

int	find_smallest(t_node *head, int size)
{
	int	i;
	int	pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num < val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (pos);
}

int	find_s_node(t_node *head, int size)
{
	int	i;
	int	pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num < val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (val);
}

int	find_l_node(t_node *head, int size)
{
	int	i;
	int	pos;
	int	val;

	i = 0;
	pos = 0;
	val = head->num;
	while (i < size)
	{
		if (head->num > val)
		{
			val = head->num;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (val);
}
