/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:17:00 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/10 10:44:28 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_modified(char **map_copy, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->g_height)
	{
		x = 0;
		while (x < game->g_width)
		{
			if (map_copy[y][x] != '1' && map_copy[y][x] != 'v'
				&& map_copy[y][x] != '0' && map_copy[y][x] != '\n')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	flood_fill(char **map_copy, int pos_x, int pos_y, t_game *game)
{
	if (pos_x < 0 || pos_x >= game->g_width || pos_y < 0
		|| pos_y >= game->g_height)
		return ;
	if (map_copy[pos_y][pos_x] == '1' || map_copy[pos_y][pos_x] == 'v')
		return ;
	map_copy[pos_y][pos_x] = 'v';
	flood_fill(map_copy, pos_x + 1, pos_y, game);
	flood_fill(map_copy, pos_x - 1, pos_y, game);
	flood_fill(map_copy, pos_x, pos_y + 1, game);
	flood_fill(map_copy, pos_x, pos_y - 1, game);
}

void	solve_map_helper(t_game *game, char **map_copy, int i)
{
	while (i < game->g_height)
	{
		map_copy[i] = (char *)malloc((game->g_width + 1) * sizeof(char));
		if (!map_copy[i])
		{
			perror("Error allocating memory for map_copy[i]");
			while (i > 0)
			{
				free(map_copy[--i]);
			}
			free(map_copy);
			return ;
		}
		ft_strlcpy(map_copy[i], game->map[i], game->g_width + 1);
		i++;
	}
}

void	solve_map(t_game *game)
{
	char	**map_copy;
	int		valid;
	int		i;

	i = 0;
	valid = 0;
	map_copy = (char **)malloc((game->g_height + 1) * sizeof(char *));
	if (!map_copy)
	{
		perror("Error allocating memory for map_copy");
		return ;
	}
	solve_map_helper(game, map_copy, i);
	map_copy[game->g_height] = NULL;
	flood_fill(map_copy, game->player_pos[0] / 64, game->player_pos[1] / 64,
		game);
	valid = check_modified(map_copy, game);
	free_map(map_copy);
	if (valid == 1)
		destroy_game(game, "map not solvable");
}
