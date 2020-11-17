/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scolen <scolen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:35:21 by scolen            #+#    #+#             */
/*   Updated: 2020/11/17 20:45:17 by scolen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*ptr;
	unsigned int	start_ptr;
	unsigned int	start_s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	start_ptr = 0;
	start_s = 0;
	ptr = (char *)malloc((len_s1 + len_s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (start_s < len_s1)
		ptr[start_ptr++] = s1[start_s++];
	start_s = 0;
	while (start_s < len_s2)
		ptr[start_ptr++] = s2[start_s++];
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t start;
	size_t src_len;

	if (dst == NULL || src == NULL)
		return (sizeof(0));
	start = 0;
	src_len = ft_strlen(src);
	if (size != 0)
		size = size - 1;
	while ((start < size) && src[start] != '\0')
	{
		dst[start] = src[start];
		start++;
	}
	if (size != 0)
		dst[start] = '\0';
	return (src_len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	if (n == 0)
		return ;
	while (n--)
		*ptr++ = '\0';
}

void	*ft_calloc(size_t num, size_t size)
{
	void *ptr;
	//int n;

	ptr = (void *)malloc(size * num);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num * size);

	return (ptr);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char *ft_strcpy(char *dest, char *src)
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
