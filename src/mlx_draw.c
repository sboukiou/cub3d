#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
/* #include "../includes/include.h" */
#include "../includes/types.h"
#include "../lib/libft/libft.h"
#include "../includes/mlx_create.h"


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

		for (int j = scale_y; j < scale_y + 23; j ++)
			for (int i = scale_x; i < scale_x + 23; i ++)
				if (i < WIN_WIDTH && j < WIN_HEIGHT)
					buffered_mlx_pixel_put(img, i, j, RED);
}

void draw_walls(t_info *info, t_mlx_img *img)
{
	int	scale_x;
	int	scale_y;

	scale_x = (WIN_WIDTH / info->map_width) * info->player_x;
	scale_y = (WIN_HEIGHT / info->map_width) * info->player_y;

		for (int j = scale_y; j < scale_y + 23; j++)
			for (int i = scale_x; i < scale_x + 23; i ++)
			{
				if (i < WIN_WIDTH && j < WIN_HEIGHT)
				{
					/*if (color == 0)*/
					/*	buffered_mlx_pixel_put(img, i, j, WHITE);*/
					/*else*/
						buffered_mlx_pixel_put(img, i, j, PINK);
				}
			}

}


int mlx_draw_map(t_mlx *mlx, t_info *info)
{
	if (info == NULL || mlx == NULL)
		return (FAILURE);

	info->map_width *= SIZE_SCALE;
	info->map_height *= SIZE_SCALE;
	mlx->player_image = mlx_xpm_file_to_image(mlx->display, "/home/sboukiou/Downloads/MLX_IMAGES/Castle/Castle_Player.xpm",
		&info->map_width, &info->map_height);
	if (mlx->player_image == NULL)
		printf("Failed to load image of the player\n") , exit(0);
	mlx->wall_image = mlx_xpm_file_to_image(mlx->display, "/home/sboukiou/Downloads/MLX_IMAGES/Castle/Castle_Wall.xpm",
			&info->map_width, &info->map_height);
	mlx->floor_image = mlx_xpm_file_to_image(mlx->display, "/home/sboukiou/Downloads/MLX_IMAGES/Castle/Castle_Floor.xpm",
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
			else if (map[y][x] == 'S')
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->player_image, x * SIZE_SCALE, y * SIZE_SCALE);
			else if (x != info->player_x || y != info->player_y)
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->floor_image, x * SIZE_SCALE, y * SIZE_SCALE);

			x++;
		}
		y++;
	}
	


	return (SUCCESS);
}
