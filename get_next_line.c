#include "get_next_line.h"

char	*gnl_remainder(char *remainder, char **line, int *read_from_file)
{
	char *p_n;
	int len;
	char *ptr;

	p_n = NULL;
	len = 0;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			p_n[0] = '\0';
			p_n++;
			*line = ft_strdup(remainder);
			while (p_n[len])
				len++;
			ft_strlcpy(remainder, p_n, len + 1);
			*read_from_file = 1;
		}
		else
		{
			ptr = *line;
			*line = ft_strjoin(*line, remainder);
			free(ptr);
			//free(remainder);
		}
	}
	else
		remainder = ft_strnew(1);
	return (p_n);
}
int i = 0;
int	get_next_line(int fd, char **line)
{
	//char buf[BUFFER_SIZE + 1];
	char *buf = malloc(BUFFER_SIZE + 1);
	static char *remainder;
	char *p_n;
	char *ptr;
	int read_from_file;
	int b;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (-1);
	p_n = NULL;
	buf[BUFFER_SIZE] = '\0';
	*line = ft_strnew(1);
	read_from_file = 0;
	p_n = gnl_remainder(remainder, line, &read_from_file);
	while (!p_n && /*(read_from_file = */(b = read(fd, buf, BUFFER_SIZE)))
	{
		buf[b] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			p_n[0] = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
			//free(buf);
			read_from_file = 1;
		}
		ptr = *line;
		//if (i != 12)
			//printf("buf: %s\n", buf);
		*line = ft_strjoin(*line, buf);
		//free(buf);
		free(ptr);
	}
	free(buf);
	return (read_from_file);
}

// int main()
// {
// 	char *line = "";
// 	int fd = open("test.txt", O_RDONLY);

// 	// get_next_line(fd, &line);
// 	// printf("%s\n\n", line);
// 	// free(line);
// 	//int i = 0;
// 	while (get_next_line(fd, &line))
// 	{
// 		i++;
// 		//printf("%s\n", line);
// 		free(line);
// 		//printf("line = %s", line);
// 	}
// 	printf("%s\n\n", line);
// 	//free(line);
// 	//free(line);
// }
