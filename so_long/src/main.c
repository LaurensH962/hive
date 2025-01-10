/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:11:56 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/09 16:48:54 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_helper(t_game *game, int i, int j)
{
	while (game->map[i][j] != '\0')
	{
		if (game->map[i][j] == '1')
			mlx_image_to_window(game->mlx, game->images[IMG_WALL], j * 64, i
				* 64);
		else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
			mlx_image_to_window(game->mlx, game->images[IMG_GROUND], j * 64, i
				* 64);
		else if (game->map[i][j] == 'E')
			mlx_image_to_window(game->mlx, game->images[IMG_GOAL], j * 64, i
				* 64);
		else if (game->map[i][j] == 'C')
		{
			mlx_image_to_window(game->mlx, game->images[IMG_GROUND], j * 64, i
				* 64);
			mlx_image_to_window(game->mlx, game->images[IMG_ITEM], j * 64, i
				* 64);
		}
		j++;
	}
}

void	draw_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		draw_map_helper(game, i, 0);
		i++;
	}
}

void	check_monitor_size(t_game *game)
{
	int32_t	monitor_width;
	int32_t	monitor_height;

	monitor_width = 0;
	monitor_height = 0;
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	if (((game->g_width - 1) * 64) > monitor_width || (game->g_height
			* 64) > monitor_height)
		destroy_game(game, "The map is larger than the monitor.");
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("no map input");
		exit(EXIT_FAILURE);
	}
	init_game(&game);
	read_map(argv[1], &game);
	game.mlx = mlx_init(game.g_width * 64, game.g_height * 64, "game", true);
	if (!game.mlx)
		destroy_game(&game, "failed to initiate mlx");
	check_monitor_size(&game);
	make_images(&game);
	draw_map(&game);
	solve_map(&game);
	load_bees(&game);
	game.images[IMG_BEE] = mlx_texture_to_image(game.mlx, game.texture);
	mlx_image_to_window(game.mlx, game.images[IMG_BEE], game.player_pos[0],
		game.player_pos[1]);
	mlx_loop_hook(game.mlx, &ft_hook, &game);
	mlx_key_hook(game.mlx, &change_bee, &game);
	mlx_loop(game.mlx);
	destroy_game(&game, "see you later");
	mlx_terminate(game.mlx);
}
