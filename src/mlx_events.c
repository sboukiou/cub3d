#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
/* #include "../includes/include.h" */
#include "../includes/types.h"
#include "../includes/mlx_draw.h"
/**
	* handle_key - Check if a given key is the escape
	* @key_code: The number corresponding to the key
	* @data: Info about the mlx and mlx_window ptrs
	* @Return: 0 , Or quit berfore if it's ESC
	*/
int	handle_key(int key_code, t_prog *prog)
{
	t_mlx	*mlx;
	t_info	*info;

	if (prog == NULL)
		return (FAILURE);
	mlx = prog->mlx;
	info = prog->info;
	if (key_code == ESCAPE)
	{
		printf("ESC clicked !!\n");
		mlx_destroy_image(mlx->display, mlx->img.img);
		mlx_destroy_image(mlx->display, mlx->player_image);
		mlx_destroy_image(mlx->display, mlx->floor_image);
		mlx_destroy_image(mlx->display, mlx->wall_image);
		mlx_destroy_window(mlx->display, mlx->window);
		mlx_destroy_display(mlx->display);
		free(info->map);
		free(mlx->display);
		exit(0);
	}
	if (key_code == XK_Up && info->map[info->player_y - 1][info->player_x]
			&& info->map[info->player_y - 1][info->player_x] != '1')
		info->player_y -= 1;
	if (key_code == XK_Left && info->map[info->player_y][info->player_x - 1]
			&& info->map[info->player_y][info->player_x - 1] != '1')
		info->player_x -= 1;
	if (key_code == XK_Down && info->map[info->player_y + 1][info->player_x]
			&& info->map[info->player_y + 1][info->player_x] != '1')
		info->player_y += 1;
	if (key_code == XK_Right && info->map[info->player_y][info->player_x + 1]
			&& info->map[info->player_y][info->player_x + 1] != '1')
		info->player_x += 1;

	mlx_draw_map(mlx, info);
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->player_image, info->player_x * SIZE_SCALE, info->player_y * SIZE_SCALE);
	return (0);
}

int	ft_exit(t_mlx *mlx)
{
	printf("Called ft_exit\n");
	mlx_destroy_image(mlx->display, mlx->img.img);
	mlx_destroy_window(mlx->display, mlx->window);
	mlx_destroy_display(mlx->display);
	free(mlx->display);
	exit(0);
}
