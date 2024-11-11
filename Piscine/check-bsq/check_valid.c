/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:22:15 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:44:21 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"bsq.h"
#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<stdlib.h>

int	ft_count_height(char *str);
int	ft_count_width(char *str);

int	check_1st_line(char *str)
{
	int	height;
	int	i;
	int	line_brk;

	height = ft_count_height(str);
	i = 0;
	line_brk = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			line_brk ++;
		i ++;
	}
	if ((line_brk - 1) != height)
		return (1);
	return (0);
}

int	check_line_widths(char *str)
{
	int	width;
	int	i;
	int	count;

	i = 0;
	count = 0;
	width = ft_count_width(str);
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (width != count)
				return (1);
			if (width == count)
				count = -1;
		}
		count++;
		i ++;
	}
	return (0);
}

int	valid_char(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i - 1] == str[i - 2] || str[i - 1] == str[i - 3]
		|| str[i - 2] == str[i - 3] || str[i - 1] < 32
		|| str[i - 1] > 126 || str[i - 2] < 32 || str[i - 2] > 126
		|| str[i - 3] < 32 || str[i - 3] > 126)
		return (1);
	j = i;
	while (str[j] != '\0')
	{
		if (str[j] != '\n' && str[j] != str[i - 2] && str[j] != str[i - 3])
			return (1);
		j ++;
	}
	if (str[0] == '\0')
		return (1);
	return (0);
}

int	check_min_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i + 1] != str[i - 2] && str[i + 1] != str[i - 3])
		return (1);
	return (0);
}

int	valid_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 7)
		return (1);
	if (check_min_map(str) == 1 || valid_char(str) == 1
		|| check_line_widths(str) == 1 || check_1st_line(str) == 1)
		return (1);
	return (0);
}
