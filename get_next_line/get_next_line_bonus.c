/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:34:22 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/20 13:57:36 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, len);
	ft_strlcat(result, s2, len + 1);
	free(s1);
	return (result);
}

struct elements	find_line(t_elems els, int fd)
{
	static char	*remainder[1024];

	if (fd < 0 || fd >= 1024)
		return (els);
	if (remainder[fd])
		els.line = remainder[fd];
	else
		els.line = ft_strdup("");
	remainder[fd] = NULL;
	while (els.bytes_read > 0)
	{
		els.newline_pos = ft_strchr(els.line, '\n');
		if (els.newline_pos != NULL)
		{
			remainder[fd] = ft_strdup(els.newline_pos + 1);
			*(els.newline_pos + 1) = '\0';
			break ;
		}
		els.bytes_read = read(fd, els.buffer, BUFFER_SIZE);
		if (els.bytes_read <= 0)
			break ;
		els.buffer[els.bytes_read] = '\0';
		els.line = ft_strjoin(els.line, els.buffer);
	}
	return (els);
}


char	*get_next_line(int fd)
{
	t_elems	els;

	els.bytes_read = 1;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	els.buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!els.buffer)
		return (NULL);
	els = find_line(els, fd);
	if (els.bytes_read < 0 || (els.bytes_read == 0 && !*els.line))
		return (free(els.buffer), free(els.line), NULL);
	return (free(els.buffer), els.line);
}

/*
#include "get_next_line_bonus.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

 int	main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	char	*line;

	if (argc == 1) // No arguments, use stdin
	{
		fd = STDIN_FILENO; // File descriptor for stdin
	}
	else if (argc == 3) // File provided
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			return (1);
		}
		fd1 = open(argv[2], O_RDONLY);
		if (fd1 == -1)
		{
			perror("Error opening file");
			return (1);
		}
	}
	else // Too many arguments
	{
		fprintf(stderr, "Usage: %s [file]\n", argv[0]);
		return (1);
	}
	// Read lines using get_next_line
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd1));
	printf("%s", line = get_next_line(fd));
	printf("%s", line = get_next_line(fd1));
	free(line);
	if (!(line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	// Close file if not stdin
	if (fd != STDIN_FILENO)
		close(fd);
	return (0);
} */
