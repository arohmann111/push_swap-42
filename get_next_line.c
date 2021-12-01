/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:33:21 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/01 17:16:43 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

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

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buf == NULL)
		return (NULL);
	r = 1;
	while (r > 0 && (gnl_strchr(save, '\n') == -1))
	{
		r = read(fd, buf, BUFFER_SIZE);
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
