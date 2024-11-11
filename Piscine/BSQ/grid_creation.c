/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:49:45 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:42:54 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_grid(char **grid, struct elements els)
{
	int	i;
	int	j;

	i = 0;
	while (i < els.row)
	{
		j = 0;
		while (j < els.col)
		{
			write(1, &grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

struct xandi	help_fill_row(char **grid, char *str, struct elements els,
		struct xandi xi)
{
	int	y;

	y = 0;
	while (y < els.col)
	{
		if (str[xi.i] != '\n')
		{
			grid[xi.x][y] = str[xi.i];
			y++;
		}
		xi.i++;
	}
	return (xi);
}

char	**fill_grid(char **grid, char *str, struct elements els)
{
	struct xandi	xi;
	int				line;

	xi.i = 0;
	line = 0;
	xi.x = 0;
	while (str[xi.i])
	{
		if (str[xi.i] == '\n')
			line++;
		if (str[xi.i] != '\n' && line >= 1)
		{
			while (xi.x < els.row)
			{
				xi = help_fill_row(grid, str, els, xi);
				xi.x++;
			}
		}
		xi.i++;
	}
	return (grid);
}

char	**create_grid(struct elements els)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	grid = (char **)malloc(els.row * sizeof(char *));
	if (grid == NULL)
		return (NULL);
	while (i < els.row)
	{
		grid[i] = (char *)malloc(els.col * sizeof(char));
		if (grid[i] == NULL)
		{
			while (j < i)
			{
				free(grid[j]);
				j++;
			}
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	free_grid(char **grid, struct elements els)
{
	int	i;

	i = 0;
	while (i < els.row)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
