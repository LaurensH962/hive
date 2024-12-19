/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:26:41 by lhaas             #+#    #+#             */
/*   Updated: 2024/12/19 17:30:49 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	if (game == NULL)
	{
		return ;
	}
	game->mlx = NULL;
	for (int i = 0; i < IMG_COUNT; i++)
	{
		game->images[i] = NULL;
	}
	game->g_width = 0;
	game->g_height = 0;
	game->map = NULL;
	game->player_pos[0] = 0;
	game->player_pos[1] = 0;
	game->texture = NULL;
	game->texture2 = NULL;
	game->texture3 = NULL;
	game->texture4 = NULL;
	game->items = 0;
	game->all_items = 0;
}

struct s_game	*make_images(t_game *game)
{
	mlx_texture_t *textures[IMG_COUNT];
	static const char *texture_paths[IMG_COUNT] = {
		"./textures/bee.png",
		"./textures/wall.png",
		"./textures/ground.png",
		"./textures/goal.png",
		"./textures/item.png"
	};
	for (int i = 1; i < IMG_COUNT; i++)
	{
		textures[i] = mlx_load_png(texture_paths[i]);
		if (!textures[i])
		{
			fprintf(stderr, "Error loading texture: %s\n", texture_paths[i]);
			ft_error();
		}
		game->images[i] = mlx_texture_to_image(game->mlx, textures[i]);
		if (!game->images[i])
		{
			fprintf(stderr, "Error creating image for texture: %s\n",
				texture_paths[i]);
			mlx_delete_texture(textures[i]);
			ft_error();
		}
		mlx_delete_texture(textures[i]);
	}
	return (game);
}
