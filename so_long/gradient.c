#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 1080
#define HEIGHT 1080
#define CWIDTH 200
#define CHEIGHT 200
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

void			ft_hook(void *param);

typedef struct s_game
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			img_idx;
}				t_game;

void	paint(void *param)
{
	t_game			*game;
	int				red;
	int				green;
	int				blue;
	int				color;
	float			scaled_x;
	float			scaled_y;
	static float	time_factor = 0;
	int				dx;
	int				dy;

	game = param;
	int cx = CWIDTH / 2;     // Circle center x
	int cy = CHEIGHT / 2;    // Circle center y
	int radius = CWIDTH / 2; // Circle radius
	time_factor += 0.01;
	for (int y = 0; y < CHEIGHT; y++)
	{
		for (int x = 0; x < CWIDTH; x++)
		{
			dx = x - cx;
			dy = y - cy;
			if ((dx * dx + dy * dy) <= (radius * radius))
			{
				scaled_x = x / (float)CWIDTH;
				scaled_y = y / (float)CHEIGHT;
				red = ((sin((scaled_x + time_factor) * M_PI * 2) * 0.5 + 0.5)
						* 255);
				green = ((cos((scaled_y + time_factor) * M_PI * 2) * 0.5 + 0.5)
						* 255);
				blue = ((sin((scaled_x + scaled_y + time_factor) * M_PI) * 0.5
							+ 0.5) * 255);
				color = (red << 24 | green << 16 | blue << 8 | 255);
				mlx_put_pixel(game->img, x, y, color);
			}
		}
	}
	game->img_idx++;
	ft_hook(game);
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->img->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->img->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->img->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->img->instances[0].x += 5;
}

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	t_game		*game;
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "smooth gradient", true);
	if (!mlx)
		ft_error();
	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("Failed to allocate memory for game");
		exit(EXIT_FAILURE);
	}
	// Create and display the image
	img = mlx_new_image(mlx, CWIDTH, CHEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	game->mlx = mlx;
	game->img = img;
	// Hook functions
	mlx_loop_hook(mlx, &paint, game);
	// mlx_loop_hook(mlx, &ft_hook, game);
	// mlx_key_hook(mlx, &handle_input, mlx);
	mlx_loop(mlx);
	// Cleanup
	free(game);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
