/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:48:04 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/01 17:17:06 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	gnl_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		len;
	int		len2;

	i = 0;
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(len + len2 + 1);
	if (dst == NULL)
		return (dst);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		dst[i + len] = s2[i];
		i++;
	}
	dst[i + len] = '\0';
	free (s1);
	return (dst);
}

void	*ft_calloc(size_t num, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (num * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
