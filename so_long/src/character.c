/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:10:53 by lhaas             #+#    #+#             */
/*   Updated: 2024/12/19 17:39:22 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_hook(void *param)
{
	t_game			*game;
	static int		cnt = 0;
	const double	frame = 1 / 2;
	static double	accum_time = 0;

	game = param;
	accum_time += game->mlx->delta_time;
	if (accum_time >= frame)
	{
		accum_time = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(game->mlx);
		if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		{
			if (game->map[game->images[IMG_BEE]->instances[0].y / 64
				- 1][game->images[IMG_BEE]->instances[0].x / 64] != '1')
			{
				game->images[IMG_BEE]->instances[0].y -= 64;
				cnt++;
				// printf("%d\n", cnt);
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'C')
				{
					game->map[game->images[IMG_BEE]->instances[0].y
						/ 64][game->images[IMG_BEE]->instances[0].x / 64] = '0';
					draw_map(game);
					redraw_bee(game, 4);
					game->items++;
				}
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'E')
				{
					if (game->items == game->all_items)
					{
						printf("YOU WON");
						printf("%d\n", game->items);
						exit(EXIT_SUCCESS);
					}
				}
			}
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		{
			if (game->map[game->images[IMG_BEE]->instances[0].y / 64
				+ 1][game->images[IMG_BEE]->instances[0].x / 64] != '1')
			{
				game->images[IMG_BEE]->instances[0].y += 64;
				cnt++;
				// printf("%d\n", cnt);
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'C')
				{
					game->map[game->images[IMG_BEE]->instances[0].y
						/ 64][game->images[IMG_BEE]->instances[0].x / 64] = '0';
					draw_map(game);
					redraw_bee(game, 3);
					game->items++;
				}
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'E')
				{
					if (game->items == game->all_items)
					{
						printf("%d\n", game->items);
						printf("YOU WON");
						exit(EXIT_SUCCESS);
					}
				}
			}
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		{
			if (game->map[game->images[IMG_BEE]->instances[0].y
				/ 64][game->images[IMG_BEE]->instances[0].x / 64 - 1] != '1')
			{
				game->images[IMG_BEE]->instances[0].x -= 64;
				cnt++;
				// printf("%d\n", cnt);
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'C')
				{
					game->map[game->images[IMG_BEE]->instances[0].y
						/ 64][game->images[IMG_BEE]->instances[0].x / 64] = '0';
					draw_map(game);
					redraw_bee(game, 2);
					game->items++;
				}
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'E')
				{
					if (game->items == game->all_items)
					{
						printf("%d\n", game->items);
						printf("YOU WON");
						exit(EXIT_SUCCESS);
					}
				}
			}
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		{
			if (game->map[game->images[IMG_BEE]->instances[0].y
				/ 64][game->images[IMG_BEE]->instances[0].x / 64 + 1] != '1')
			{
				game->images[IMG_BEE]->instances[0].x += 64;
				cnt++;
				// printf("%d\n", cnt);
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'C')
				{
					game->map[game->images[IMG_BEE]->instances[0].y
						/ 64][game->images[IMG_BEE]->instances[0].x / 64] = '0';
					draw_map(game);
					redraw_bee(game, 1);
					game->items++;
				}
				if (game->map[game->images[IMG_BEE]->instances[0].y
					/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'E')
				{
					if (game->items == game->all_items)
					{
						printf("%d\n", game->items);
						printf("YOU WON");
						exit(EXIT_SUCCESS);
					}
				}
			}
		}
	}
}

void	redraw_bee(t_game *game, int direction)
{
	int	img_x;
	int	img_y;

	if (direction == 4)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture4);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
	if (direction == 3)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture3);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
	if (direction == 2)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
	if (direction == 1)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture2);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
}

void	change_bee(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		img_x;
	int		img_y;

	game = param;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture2);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture3);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		img_x = game->images[IMG_BEE]->instances[0].x;
		img_y = game->images[IMG_BEE]->instances[0].y;
		mlx_delete_image(game->mlx, game->images[IMG_BEE]);
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture4);
		mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->images[IMG_WALL], j * 64, i
					* 64);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->images[IMG_GROUND], j * 64,
					i * 64);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->images[IMG_GOAL], j * 64, i
					* 64);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->images[IMG_ITEM], j * 64, i
					* 64);
			j++;
		}
		j = 0;
		i++;
	}
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
	if (!game.map)
	{
		perror("no valid map");
		exit(EXIT_FAILURE);
	}
	game.mlx = mlx_init(game.g_width * 64, game.g_height * 64, "char walk",
			true);
	if (!game.mlx)
		ft_error();
	// Convert texture to a displayable image
	make_images(&game);
	draw_map(&game);
	//	ft_error();
	game.texture = mlx_load_png("./textures/bee.png");
	game.texture2 = mlx_load_png("./textures/bee_r.png");
	game.texture3 = mlx_load_png("./textures/bee_down.png");
	game.texture4 = mlx_load_png("./textures/bee_up.png");
	game.images[IMG_BEE] = mlx_texture_to_image(game.mlx, game.texture);
	// mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game.mlx, game.images[IMG_BEE], game.player_pos[0],
		game.player_pos[01]);
	//--------PRINT STACK-----------
	printf("mlx = %p\n"
			"images[0] = %p\n"
			"height = %d\n"
			"width = %d\n"
			"map 1st row = %s\n"
			"playerx = %d\n"
			"playery = %d\n"
			"tex1 = %p\n"
			"tex2 = %p\n"
			"item = %d\n"
			"all_items = %d\n",
			game.mlx,
			game.images[0],
			game.g_height,
			game.g_width,
			game.map[0],
			game.player_pos[0],
			game.player_pos[1],
			game.texture,
			game.texture2,
			game.items,
			game.all_items);
	//--------PRINT STACK-----------
	// Hook functions
	// mlx_loop_hook(mlx, &ft_character, game);
	mlx_loop_hook(game.mlx, &ft_hook, &game);
	mlx_key_hook(game.mlx, &change_bee, &game);
	mlx_loop(game.mlx);
	// Cleanup
	// free(game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
