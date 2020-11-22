/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scolen <scolen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:42:29 by scolen            #+#    #+#             */
/*   Updated: 2020/11/22 12:59:30 by scolen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	unsigned int	start_ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	start_ptr = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (*s1)
		ptr[start_ptr++] = *s1++;
	while (*s2)
		ptr[start_ptr++] = *s2++;
	ptr[start_ptr] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *str)
{
	unsigned int	start;
	unsigned int	length_str;
	char			*ptr;

	start = 0;
	length_str = ft_strlen(str);
	ptr = malloc((length_str + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (start < length_str)
	{
		ptr[start] = str[start];
		start++;
	}
	ptr[start] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	symbol;
	unsigned int	start;
	char			*ptr;

	start = 0;
	ptr = (char *)str;
	symbol = (unsigned char)ch;
	while (ptr[start] != '\0')
	{
		if (ptr[start] == symbol)
			return (&ptr[start]);
		start++;
	}
	if (ptr[start] == symbol)
		return (&ptr[start]);
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
