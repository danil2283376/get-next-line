#include "get_next_line.h"

char	*gnl_remainder(char *remainder, char **line/*, int *read_from_file*/)
{
	char *p_n;
	char *ptr;

	p_n = NULL;
	if (remainder)
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			p_n[0] = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			ptr = *line;
			*line = ft_strjoin(*line, remainder);
			free(ptr);
			free(remainder);
		}
	else
		remainder = ft_strnew(0);
	return (p_n);
}

int	get_next_line(int fd, char **line)
{
	char *buf;
	static char *remainder[1024];
	char *p_n;
	char *ptr;
	int read_next;

	if (fd < 0 || BUFFER_SIZE < 1 || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_strnew(0);
	p_n = gnl_remainder(remainder[fd], line);
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
		*line = ft_strjoin(*line, buf);
		free(ptr);
	}
	free(buf);
	if (read_next == 0)
		remainder[fd] = ft_strnew(0);
	return (p_n != NULL ? 1 : 0/*read_from_file*/);
}

int main()
{
	char *line = "";
	int fd = open("test.txt", O_RDONLY);

	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
		//printf("line = %s", line);
	}
	//printf("%s\n\n", line);
	free(line);
}
