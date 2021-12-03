/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:24 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 15:55:09 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*gnl_strjoin(char *s1, char *s2)
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

static int	gnl_strchr(const char *str, int c)
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

static char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (save == NULL)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)ft_calloc((i + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] = save[i];
	return (line);
}

static char	*new_save(char *save)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || save[i + 1] == '\0')
	{
		free (save);
		return (NULL);
	}
	new_save = (char *)ft_calloc((ft_strlen(save) - i), sizeof(char));
	if (new_save == NULL)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free (save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*buf;
	char		*line;
	int			r;

	buf = (char *)ft_calloc((1 + 1), sizeof(char));
	if (buf == NULL)
		return (NULL);
	r = 1;
	while (r > 0 && (gnl_strchr(save, '\n') == -1))
	{
		r = read(fd, buf, 1);
		if (r == -1 || (r == 0 && save == NULL))
		{
			free (buf);
			return (NULL);
		}
		buf[r] = '\0';
		save = gnl_strjoin(save, buf);
	}
	free (buf);
	line = get_line(save);
	save = new_save(save);
	return (line);
}
