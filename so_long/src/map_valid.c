/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:46:22 by lhaas             #+#    #+#             */
/*   Updated: 2024/12/19 17:24:35 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_borders(char **map, int len)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (map[0][x] != '\n')
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	while (map[y + 1] != NULL)
	{
		if (map[y][0] != '1' || map[y][len - 2] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (map[y][x] && map[y][x] != '\n')
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

t_game	*check_items(t_game *game)
{
	int	y;
	int	x;
	int	start;
	int	exit;

	y = 1;
	x = 1;
	start = 0;
	exit = 0;
	while (game->map[y + 1] != NULL)
	{
		while (x < game->g_width - 2)
		{
			if (game->map[y][x] == 'E')
				exit++;
			else if (game->map[y][x] == 'P')
			{
				game->player_pos[0] = x * 64;
				game->player_pos[1] = y * 64;
				start++;
			}
			else if (game->map[y][x] == 'C')
				game->all_items++;
			printf("%d\n", game->all_items);
			x++;
		}
		y++;
		x = 1;
	}
	if (exit != 1 || start != 1 || game->all_items < 1)
		return (NULL);
	return (game);
}

static int	check_length(char **map)
{
	int	len;
	int	len2;
	int	y;

	y = 1;
	len = ft_strlen(map[0]);
	while (map[y] != NULL)
	{
		len2 = ft_strlen(map[y]);
		if (len2 != len)
			return (0);
		y++;
	}
	return (len);
}

t_game	*valid_map(t_game *game)
{
	int	borders;

	game->g_width = check_length(game->map);
	game = check_items(game);
	borders = check_borders(game->map, game->g_width);
	if (borders == 0 || !game || game->g_width == 0)
	{
		free_map(game->map);
		return (NULL);
	}
	return (game);
}

static int	count_lines(char *file_name)
{
	int		count;
	int		fd;
	char	c;

	count = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	read_map(char *file_name, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	game->g_height = count_lines(file_name);
	fd = open(file_name, O_RDONLY);
	game->map = (char **)malloc((game->g_height + 1) * sizeof(char *));
	if (!game->map)
	{
		perror("Error allocating map");
		close(fd);
		// return (game);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = gnl_ft_strdup(line);
		if (!game->map[i])
		{
			perror("Error duplicating line");
			while (i > 0)
				free(game->map[--i]);
			free(game->map);
			free(line);
			close(fd);
			// return (game);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	game->map[i] = NULL;
	game = valid_map(game);
	// return (game);
}
