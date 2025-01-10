/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:10:53 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/09 16:49:11 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_redraw(t_game *game)
{
	int		bee_x;
	int		bee_y;
	int		item_x;
	int		item_y;
	size_t	i;

	bee_x = game->images[IMG_BEE]->instances[0].x / 64;
	bee_y = game->images[IMG_BEE]->instances[0].y / 64;
	i = 0;
	if (game->map[bee_y][bee_x] == 'C')
	{
		game->map[bee_y][bee_x] = '0';
		while (i < game->images[IMG_ITEM]->count)
		{
			item_x = game->images[IMG_ITEM]->instances[i].x / 64;
			item_y = game->images[IMG_ITEM]->instances[i].y / 64;
			if (item_x == bee_x && item_y == bee_y)
			{
				game->images[IMG_ITEM]->instances[i].enabled = false;
				break ;
			}
			i++;
		}
		game->items++;
	}
}

int	move_bee(t_game *game, int y, int x, int cnt)
{
	if (game->map[game->images[IMG_BEE]->instances[0].y / 64
			+ y][game->images[IMG_BEE]->instances[0].x / 64 + x] != '1')
	{
		if (y < 0)
			game->images[IMG_BEE]->instances[0].y -= 64;
		else if (y > 0)
			game->images[IMG_BEE]->instances[0].y += 64;
		else if (x < 0)
			game->images[IMG_BEE]->instances[0].x -= 64;
		else if (x > 0)
			game->images[IMG_BEE]->instances[0].x += 64;
		cnt++;
		printf("%d\n", cnt);
		if (game->map[game->images[IMG_BEE]->instances[0].y
				/ 64][game->images[IMG_BEE]->instances[0].x / 64] == 'E')
		{
			if (game->items == game->all_items)
				destroy_game(game, "YOU WON");
		}
	}
	return (cnt);
}

void	redraw_bee(t_game *game, int direction)
{
	int	img_x;
	int	img_y;

	img_x = game->images[IMG_BEE]->instances[0].x;
	img_y = game->images[IMG_BEE]->instances[0].y;
	mlx_delete_image(game->mlx, game->images[IMG_BEE]);
	if (direction == 4)
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture4);
	if (direction == 3)
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture3);
	if (direction == 2)
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture);
	if (direction == 1)
		game->images[IMG_BEE] = mlx_texture_to_image(game->mlx, game->texture2);
	mlx_image_to_window(game->mlx, game->images[IMG_BEE], img_x, img_y);
}

void	load_bees(t_game *game)
{
	game->texture = mlx_load_png("./textures/bee.png");
	game->texture2 = mlx_load_png("./textures/bee_r.png");
	game->texture3 = mlx_load_png("./textures/bee_down.png");
	game->texture4 = mlx_load_png("./textures/bee_up.png");
}
