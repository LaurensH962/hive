/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contents_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:38:53 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/09 14:10:30 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_items(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (game->map[y + 1] != NULL)
	{
		x = 1;
		while (x < game->g_width - 2)
		{
			if (game->map[y][x] == 'E')
				game->exit_count++;
			else if (game->map[y][x] == 'P')
			{
				game->player_pos[0] = x * 64;
				game->player_pos[1] = y * 64;
				game->start_count++;
			}
			else if (game->map[y][x] == 'C')
				game->all_items++;
			x++;
		}
		y++;
	}
	if (game->exit_count != 1 || game->start_count != 1 || game->all_items < 1)
		destroy_game(game, "no valid map1");
}

void	check_length(t_game *game)
{
	int	len2;
	int	y;

	y = 1;
	game->g_width = ft_strlen(game->map[0]);
	while (game->map[y] != NULL)
	{
		len2 = ft_strlen(game->map[y]);
		if (len2 != game->g_width)
			destroy_game(game, "no valid map2");
		y++;
	}
}

void	check_wrong_items(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->g_width - 1)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'P' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'C')
				destroy_game(game, "no valid map3");
			x++;
		}
		y++;
	}
}

void	valid_map(t_game *game)
{
	int	borders;

	check_length(game);
	check_items(game);
	check_wrong_items(game);
	borders = check_borders(game->map, game->g_width);
	if (borders == 0)
		destroy_game(game, "no valid map");
}
