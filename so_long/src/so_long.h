/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:05:49 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/23 09:43:39 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
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
}					t_image_index;

typedef struct s_game
{
	mlx_image_t		*images[IMG_COUNT];
	mlx_t			*mlx;
	int				player_pos[2];
	int				g_width;
	int				g_height;
	int				items;
	int				start_count;
	int				exit_count;
	int				all_items;
	char			**map;
	mlx_texture_t	*texture;
	mlx_texture_t	*texture2;
	mlx_texture_t	*texture3;
	mlx_texture_t	*texture4;
}					t_game;

int32_t				main(int argc, char **argv);
void				change_bee(mlx_key_data_t keydata, void *param);
void				ft_hook(void *param);
int					ft_hook_helper(t_game *game, int cnt);

void				read_map(char *file_name, t_game *game);
void				init_game(t_game *game);
struct s_game		*make_images(t_game *game);
void				destroy_game(t_game *game, char *error_msg);
void				draw_map(t_game *game);
void				redraw_bee(t_game *game, int direction);
void				solve_map(t_game *game);
void				free_map(char **map);
void				redraw_bee(t_game *game, int direction);
void				check_for_redraw(t_game *game);
int					move_bee(t_game *game, int y, int x, int cnt);
void				load_bees(t_game *game);

void				valid_map(t_game *game);

#endif
