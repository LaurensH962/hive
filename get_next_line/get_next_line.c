/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:02:20 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/14 16:07:01 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 8

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s) + 1;
	p = (char *)malloc(len);
	if (p == NULL)
		return (NULL);
	if (p)
		ft_memcpy(p, s, len);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	d_len;
	size_t	s_len;

	if (size == 0 && (!dst || !src))
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	count = 0;
	if (size <= d_len)
		return (s_len + size);
	else if (size > d_len)
	{
		while (count < (size - d_len - 1) && src[count] != '\0')
		{
			dst[d_len + count] = src[count];
			count++;
		}
	}
	dst[d_len + count] = '\0';
	return (d_len + s_len);
}

char	*str_join(char *s1, char *s2)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	free(s1);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;
	char		*newline_pos;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (remainder)
		line = remainder;
	else
		line = ft_strdup("");
	remainder = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = str_join(line, buffer);
		if ((newline_pos = ft_strchr(line, '\n')))
		{
			*newline_pos = '\0';
			remainder = ft_strdup(newline_pos + 1);
			break ;
		}
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && !*line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
