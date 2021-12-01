/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:44:57 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/01 16:48:27 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_check(char *s, int *error, int *minus)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == '-' || s[i] == '+')
			sign += 1;
		if (ft_strchr("0123456789+- ", s[i]) == 0)
		{
			*error = -1;
			return ;
		}
		i++;
	}
	if (sign == 1 && s[0] == '-')
		*minus = -1;
	if (sign > 1 || i > 11 || (sign == 1
			&& (s[0] != '-' && s[0] != '+')) || s[i] != '\0')
		*error = -1;
}

int	ft_atoi(char *str, int *error)
{
	int				i;
	unsigned int	res;
	int				sign;

	i = 0;
	sign = 1;
	res = 0;
	ft_check(str, error, &sign);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX || (res > INT_MAX && sign == -1))
		*error = -1;
	return (sign * res);
}
