/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:20:57 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/10 10:26:29 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
}

void	delete_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < IMG_COUNT)
	{
		mlx_delete_image(game->mlx, game->images[i]);
		i++;
	}
}

void	destroy_game(t_game *game, char *error_msg)
{
	int	i;

	i = 0;
	if (game->texture)
	{
		mlx_delete_texture(game->texture);
		mlx_delete_texture(game->texture2);
		mlx_delete_texture(game->texture3);
		mlx_delete_texture(game->texture4);
	}
	free_map(game->map);
	ft_printf("%s\n", error_msg);
	if (game->mlx)
		mlx_close_window(game->mlx);
	exit(EXIT_FAILURE);
}
