#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
/* #include "../includes/include.h" */
#include "../includes/types.h"
#include "../lib/libft/libft.h"
#include "../includes/mlx_create.h"

void draw_player(int pos_x, int pos_y, t_mlx_img *img, t_info *info)
{
	int	scale_x;
	int	scale_y;

	scale_x = (WIN_WIDTH / info->map_width) * pos_x;
	scale_y = (WIN_HEIGHT / info->map_width) * pos_y;

		for (int j = scale_y; j < scale_y + 23; j ++)
			for (int i = scale_x; i < scale_x + 23; i ++)
				if (i < WIN_WIDTH && j < WIN_HEIGHT)
					buffered_mlx_pixel_put(img, i, j, RED);
}

void draw_walls(t_info *info, t_mlx_img *img)
{
	if (info == NULL || img == NULL)
}
{
	int	scale_x;
	int	scale_y;

	scale_x = (WIN_WIDTH / info->map_width) * pos_x;
	scale_y = (WIN_HEIGHT / info->map_width) * pos_y;

		for (int j = scale_y; j < scale_y + 23; j++)
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


int mlx_draw_map(t_mlx *mlx, t_info *info)
{
	if (info == NULL || mlx == NULL)
		return (FAILURE);
	for (int i = 0; i < WIN_HEIGHT; i++)
		for(int j = 0; j < WIN_WIDTH; j++)
			buffered_mlx_pixel_put(&mlx->img, j, i, 0x16082f);
	draw_walls(t_info *info, mlx->img);
	draw_player(info->player_x, info->player_y, &mlx->img, info);
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->img.img, 0, 0);
	return (SUCCESS);
}
