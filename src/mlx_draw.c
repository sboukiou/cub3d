#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
/* #include "../includes/include.h" */
#include "../includes/types.h"
#include "../lib/libft/libft.h"
#include "../includes/mlx_create.h"

int mlx_draw_map(t_mlx *mlx, t_info *info)
{
	if (info == NULL || mlx == NULL)
		return (FAILURE);
	for (int i = 0; i < info->map_height; i++)
		for(int j = 0; j < info->map_width; j++)
			buffered_mlx_pixel_put(&mlx->img, j, i, 0x16082f);
	for (int i = 0; i < info->map_height; i++)
		for (int j = 0; j < info->map_width; j++)
			draw_wall(j, i, &mlx->img,info->map[i][j], info);
	draw_player(info->player_x, info->player_y, &mlx->img, info);
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->img.img, 0, 0);
	return (SUCCESS);
}
