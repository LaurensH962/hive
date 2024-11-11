/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:54:14 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:41:03 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**print_sqr(char **grid, struct square max_sqr, struct elements els)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_sqr.length)
	{
		j = 0;
		while (j < max_sqr.length)
		{
			grid[max_sqr.x + i][max_sqr.y + j] = els.fill;
			j++;
		}
		i++;
	}
	return (grid);
}

int	check_valid_sqr(char **grid, t_elems els, struct square sqr, int temp_l)
{
	int	i;
	int	j;

	i = 0;
	while (i < temp_l && (i + sqr.x) < els.row)
	{
		if (grid[i + sqr.x][(temp_l - 1) + sqr.y] != els.empt)
			return (1);
		i++;
	}
	j = 0;
	while (j < temp_l && (j + sqr.y) < els.col)
	{
		if (grid[(temp_l - 1) + sqr.x][j + sqr.y] != els.empt)
			return (1);
		j++;
	}
	return (0);
}

struct square	find_square(char **grid, t_elems els, struct square sqr)
{
	int	temp_l;

	temp_l = 1;
	while (temp_l <= els.row && temp_l <= els.col && ((temp_l - 1)
			+ sqr.y) < els.col && ((temp_l - 1) + sqr.x) < els.row)
	{
		if (check_valid_sqr(grid, els, sqr, temp_l) == 1)
		{
			sqr.length = temp_l - 1;
			return (sqr);
		}
		temp_l++;
	}
	sqr.length = temp_l - 1;
	return (sqr);
}

char	**solve(char **grid, struct elements els)
{
	struct square	max_sqr;
	struct square	f_sqr;

	f_sqr.length = 0;
	f_sqr.x = 0;
	f_sqr.y = 0;
	max_sqr = find_square(grid, els, f_sqr);
	while (f_sqr.x < els.row)
	{
		f_sqr.y = 0;
		while (f_sqr.y < els.col)
		{
			f_sqr = find_square(grid, els, f_sqr);
			if (max_sqr.length < f_sqr.length)
				max_sqr = f_sqr;
			f_sqr.y++;
		}
		f_sqr.x++;
	}
	print_sqr(grid, max_sqr, els);
	return (grid);
}
