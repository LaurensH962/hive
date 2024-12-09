#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 1080
#define HEIGHT 1080
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif


typedef struct s_game
{
	mlx_image_t *img;
	mlx_t *mlx;
}			t_game;


void	paint(void* param)
{
	t_game* game = param;

	int				red;
	int				green;
	int				blue;
	int				color;
	int				alpha;
	float			scaled_x;
	float			scaled_y;
	static float	time_factor = 0;

	alpha = 255;
	time_factor += 0.0005;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			scaled_x = x / (float)WIDTH;
			scaled_y = y / (float)HEIGHT;
			red = ((sin((scaled_x + time_factor)  * M_PI * 2) * 0.5	+ 0.5) * 255);
			green = ((cos((scaled_y + time_factor)  * M_PI * 2) * 0.5	+ 0.5) * 255);
			blue = ((sin((scaled_x + scaled_y + time_factor) * M_PI) * 0.5 + 0.5) * 255);
			color = (red << 24 | green << 16 | blue << 8 | alpha);
			mlx_put_pixel(game->img, x, y, color);
		}
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	handle_input(mlx_key_data_t keydata, void* param)
{
	mlx_t* mlx = param;

	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
}


static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}


int32_t main(void)
{
    t_game* game;
    mlx_t* mlx;

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
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
        ft_error();
    mlx_put_pixel(img, 0, 0, 0xFF0000FF);

    game->mlx = mlx;
    game->img = img;

    // Hook functions
    mlx_loop_hook(mlx, &paint, game);
    mlx_key_hook(mlx, &handle_input, mlx);
    mlx_loop(mlx);

    // Cleanup
    free(game);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
