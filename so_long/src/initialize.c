/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:26:41 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/23 15:45:19 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	i;

	i = 0;
	if (game == NULL)
		return ;
	game->mlx = NULL;
	while (i < IMG_COUNT)
	{
		game->images[i] = NULL;
		i++;
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
	game->start_count = 0;
	game->exit_count = 0;
	game->all_items = 0;
}

struct s_game	*make_images(t_game *game)
{
	int					i;
	mlx_texture_t		*textures[IMG_COUNT];
	static const char	*texture_paths[IMG_COUNT] = {"./textures/bee.png",
		"./textures/wall.png", "./textures/ground.png",
		"./textures/goal.png", "./textures/item.png"};

	i = 0;
	while (i < IMG_COUNT)
	{
		textures[i] = mlx_load_png(texture_paths[i]);
		if (!textures[i])
			destroy_game(game, "error loading texture");
		game->images[i] = mlx_texture_to_image(game->mlx, textures[i]);
		if (!game->images[i])
		{
			mlx_delete_texture(textures[i]);
			destroy_game(game, "Error creating image for texture");
		}
		mlx_delete_texture(textures[i]);
		i++;
	}
	return (game);
}
