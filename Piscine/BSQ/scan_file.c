/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:36:09 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:41:56 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(char *file_name)
{
	int		byteread;
	char	c;
	char	*str;
	int		map;

	byteread = 0;
	map = open(file_name, O_RDONLY);
	while (read(map, &c, 1) > 0)
		byteread++;
	close(map);
	str = (char *)malloc((byteread + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	map = open(file_name, O_RDONLY);
	read(map, str, byteread);
	str[byteread] = '\0';
	close(map);
	return (str);
}

char	find_char(char *str, int a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	return (str[i - a]);
}

int	ft_count_height(char *str)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (str[i] != '\n')
		i++;
	while (j < (i - 3))
	{
		nbr = nbr * 10 + (str[j] - '0');
		j++;
	}
	return (nbr);
}

int	ft_count_width(char *str)
{
	int	i;
	int	count;
	int	line;

	i = 0;
	line = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line++;
		if (str[i] != '\n' && line == 1)
			count++;
		i++;
	}
	return (count);
}
