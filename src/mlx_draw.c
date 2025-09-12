#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
/* #include "../includes/include.h" */
#include "../includes/types.h"

static	void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	t_mlx_img *img;

	img = &mlx->draw_image;
	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned char *)dst = color;
}

int mlx_draw_minimap(t_mlx *mlx, t_info *info)
{
	if (info == NULL || mlx == NULL)
		return (FAILURE);


	info->map_width *= SIZE_SCALE;
	info->map_height *= SIZE_SCALE;

	mlx->player_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_Player_Big.xpm",
		&info->map_width, &info->map_height);
	mlx->wall_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_Wall_Big.xpm",
			&info->map_width, &info->map_height);
	mlx->floor_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_Floor_Big.xpm",
			&info->map_width, &info->map_height);
	int x = 0;
	int y = 0;
	char **map = info->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->wall_image, x * SIZE_SCALE, y * SIZE_SCALE);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->floor_image, x * SIZE_SCALE, y * SIZE_SCALE);
			else if (map[y][x] == 'N')
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->player_image, x * SIZE_SCALE, y * SIZE_SCALE);
			else if (x != info->player_x || y != info->player_y)
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->floor_image, x * SIZE_SCALE, y * SIZE_SCALE);

			x++;
		}
		y++;
	}
	return (SUCCESS);
}


bool	mlx_draw_field(t_mlx *mlx, t_info *info)
{
	mlx->draw_image.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->draw_image.img == NULL)
		return (printf("Filed to create field image\n"), false);
	if (mlx == NULL || info == NULL)
		return (false);
	return (true);
	for (int i = 0; i < WIN_HEIGHT; i++)
		for (int j  = 0; j < WIN_WIDTH; j++)
			put_pixel(mlx, j, i, WHITE);
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->draw_image.img, 0, 0);
}
