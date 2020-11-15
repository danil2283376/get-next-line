/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scolen <scolen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:36:12 by scolen            #+#    #+#             */
/*   Updated: 2020/11/14 15:12:02 by scolen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
//# define BUFFER_SIZE 30


char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *destination, const void *source, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		get_next_line(int fd, char **line);
char	*ft_strnew(size_t size);

#endif
