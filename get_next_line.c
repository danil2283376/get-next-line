/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scolen <scolen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:42:09 by scolen            #+#    #+#             */
/*   Updated: 2020/11/22 14:40:28 by scolen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char		*gnl_remainder(char **remainder, char **line)
{
	char *p_n;
	char *leaks;

	p_n = NULL;
	if (*remainder)
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(*remainder);
			leaks = *remainder;
			*remainder = ft_strdup(++p_n);
			free(leaks);
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	else
		*line = ft_strdup("");
	return (p_n);
}

static int		return_fail_value(char *buf)
{
	if (buf)
		free(buf);
	return (-1);
}

static char		*clean_ft_strjoin(char *line, char *buff)
{
	char	*leaks;

	leaks = line;
	if (!(line = ft_strjoin(line, buff)))
		return (NULL);
	free(leaks);
	return (line);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char *remainder;
	char		*p_n;
	int			read_next;

	buf = NULL;
	if (BUFFER_SIZE < 1 || !(buf = malloc(BUFFER_SIZE + 1))
		|| (read(fd, buf, 0) < 0))
		return (-1);
	p_n = gnl_remainder(&remainder, line);
	while (!p_n && (read_next = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_next] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			if (!(remainder = ft_strdup(++p_n)))
				return (return_fail_value(buf));
		}
		if (!(*line = clean_ft_strjoin(*line, buf)))
			return (return_fail_value(buf));
	}
	free(buf);
	return (p_n != NULL ? 1 : 0);
}
