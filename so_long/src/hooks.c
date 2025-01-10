/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:20:54 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/09 16:21:31 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_bee(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		redraw_bee(game, 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		redraw_bee(game, 2);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		redraw_bee(game, 3);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		redraw_bee(game, 4);
}

int	ft_hook_helper(t_game *game, int cnt)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		destroy_game(game, "Fly you fool");
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		cnt = move_bee(game, -1, 0, cnt);
		check_for_redraw(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		cnt = move_bee(game, 1, 0, cnt);
		check_for_redraw(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		cnt = move_bee(game, 0, -1, cnt);
		check_for_redraw(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		cnt = move_bee(game, 0, 1, cnt);
		check_for_redraw(game);
	}
	return (cnt);
}

void	ft_hook(void *param)
{
	t_game			*game;
	static int		cnt = 0;
	const double	frame = 1 / 50.0;
	static double	accum_time = 0;

	game = param;
	accum_time += game->mlx->delta_time;
	if (accum_time >= frame)
	{
		accum_time = 0;
		cnt = ft_hook_helper(game, cnt);
	}
}
