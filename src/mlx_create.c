#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
#include "../includes/types.h"

int mlx_init_display(t_mlx *mlx)
{
	mlx->display = mlx_init();
	if (mlx->display == NULL)
		return (FAILURE);
	mlx->window = mlx_new_window(mlx->display, WIN_WIDTH, WIN_HEIGHT, "Playground");
	if (mlx->window == NULL)
		return (FAILURE);
	mlx->img.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img == NULL)
		return (FAILURE);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
		&mlx->img.bpp, &mlx->img.llen, &mlx->img.endian);
	if (mlx->img.addr == NULL)
		return (FAILURE);
	return (SUCCESS);
}

void	buffered_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void draw_player(int pos_x, int pos_y, t_mlx_img *img, t_info *info)
{
	int	scale_x;
	int	scale_y;

	scale_x = (WIN_WIDTH / info->map_width) * pos_x;
	scale_y = (WIN_HEIGHT / info->map_width) * pos_y;
		;

		for (int j = scale_y; j < scale_y + 23; j ++)
			for (int i = scale_x; i < scale_x + 23; i ++)
				if (i < WIN_WIDTH && j < WIN_HEIGHT)
					buffered_mlx_pixel_put(img, i, j, RED);
}

void draw_wall(int pos_x, int pos_y, t_mlx_img *img, int color, t_info *info)
{
	int	scale_x;
	int	scale_y;

	scale_x = (WIN_WIDTH / info->map_width) * pos_x;
	scale_y = (WIN_HEIGHT / info->map_width) * pos_y;
		;

		for (int j = scale_y; j < scale_y + 23; j ++)
			for (int i = scale_x; i < scale_x + 23; i ++)
			{
				if (i < WIN_WIDTH && j < WIN_HEIGHT)
				{
					if (color == 0)
						buffered_mlx_pixel_put(img, i, j, WHITE);
					else
						buffered_mlx_pixel_put(img, i, j, PINK);
				}
			}

}

