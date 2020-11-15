/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scolen <scolen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:55:16 by scolen            #+#    #+#             */
/*   Updated: 2020/11/15 12:34:52 by scolen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line_remainder(char *remainder,char **line, int *read_from_file)
{
	char *p_n;
	int len_p_n;

	p_n = NULL;
	len_p_n = 0;
	if (remainder != NULL)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			p_n[0] = '\0';
			p_n++;
			*line = ft_strdup(remainder);
			len_p_n = ft_strlen(p_n);
			ft_strlcpy(remainder, p_n, len_p_n + 1);
			char *new_str = ft_strdup(remainder);
			free(remainder);
			remainder = new_str;
			//*read_from_file = 1;
		}
		else
		{
			*line = ft_strjoin(*line, remainder);
			//free(remainder);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	char *p_n;
	static char *remainder;
	int read_from_file;
	char *ptr;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	read_from_file = 0;
	p_n = NULL;
	buf[BUFFER_SIZE] = '\0';
	*line = ft_strnew(1);
	if (remainder != NULL)
		p_n = get_next_line_remainder(remainder, line, &read_from_file);
	while (!p_n && (read_from_file = read(fd, &buf, BUFFER_SIZE)))
	{
		if ((p_n = ft_strchr(buf, '\n')))
		{
			p_n[0] = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		//printf("line: %s\n");
		ptr = *line;
		*line = ft_strjoin(*line, buf);
		free(ptr);
	}
	//free(remainder);
	if (ft_strlen(*line) || ft_strlen(remainder) || read_from_file)
		read_from_file = 1;
	return (read_from_file);
}

// int main()
// {
// 	char *line = "";
// 	int fd = open("test.txt", O_RDONLY);
// 	// get_next_line(fd, &line);
// 	// free(line);

// 	// get_next_line(fd, &line);
// 	// free(line);

// 	// get_next_line(fd, &line);
// 	// free(line);

// 	// get_next_line(fd, &line);
// 	// free(line);

// 	// get_next_line(fd, &line);
// 	// free(line);
//  	while (get_next_line(fd, &line))
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		//printf("line = %s", line);
// 	}
// 	//free(line);
// }
