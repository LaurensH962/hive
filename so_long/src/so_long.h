/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:05:49 by lhaas             #+#    #+#             */
/*   Updated: 2024/12/19 16:37:57 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef enum e_image_index
{
	IMG_BEE = 0,
	IMG_WALL,
	IMG_GROUND,
	IMG_GOAL,
	IMG_ITEM,
	IMG_COUNT
}				t_image_index;

/* typedef struct s_items
{

	int			start;
	int		player_pos[2];
	int			g_width;
	int			g_height;
	char		**map;
}				t_items; */

typedef struct s_game
{
	mlx_image_t	*images[IMG_COUNT];
	mlx_t		*mlx;
	int		player_pos[2];
	int			g_width;
	int			g_height;
	int			items;
	int			all_items;
	char		**map;
	mlx_texture_t	*texture;
	mlx_texture_t	*texture2;
	mlx_texture_t	*texture3;
	mlx_texture_t	*texture4;
}				t_game;

int32_t			main(int argc, char **argv);
void			change_bee(mlx_key_data_t keydata, void *param);
void			ft_hook(void *param);

void	read_map(char *file_name, t_game *game);
void	init_game(t_game *game);
struct s_game	*make_images(t_game *game);
void	ft_error(void);
void	draw_map(t_game *game);
void	redraw_bee(t_game *game, int direction);

#endif
