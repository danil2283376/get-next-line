/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scolen <scolen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:12:56 by scolen            #+#    #+#             */
/*   Updated: 2020/11/18 21:46:48 by scolen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*gnl_remainder(char **remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (*remainder)
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n++ = '\0';
			*line = ft_strdup(*remainder);
			if (*p_n)
				ft_strcpy(*remainder, p_n);
			else
			{
				free(*remainder);
				*remainder = NULL;
			}
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			remainder = NULL;
		}
	else
		*line = ft_strdup("");
	return (p_n);
}

static int		return_eof(int r_n, char **remainder, char *p_n, char *buf)
{
	free(buf);
	if (r_n == 0)
		*remainder = ft_strdup("");
	if (p_n != NULL || r_n)
		return (1);
	else
		return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char *remainder[1024];
	char		*p_n;
	char		*ptr;
	int			read_next;

	if (fd < 0 || BUFFER_SIZE < 1 || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = NULL;
	p_n = gnl_remainder(&remainder[fd], line);
	while (!p_n && (read_next = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_next == -1)
			return (-1);
		buf[read_next] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			p_n[0] = '\0';
			if (!(remainder[fd] = ft_strdup(++p_n)))
				return (-1);
		}
		ptr = *line;
		*line = ft_strjoin(ptr, buf);
	}
	return (return_eof(read_next, &remainder[fd], p_n, buf));
}
