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
		mlx_destroy_window(mlx->display, mlx->window);
		mlx_destroy_display(mlx->display);
		/*for (int i = 0; i < info->map_height; i++)*/ // Why its causig segv, isn't it allocated
		/*	free(info->map[i]);*/
		free(info->map);
		free(mlx->display);
		exit(0);
	}
	if (key_code == XK_k && info->player_y - 5 > 0)
		info->player_y -= 5;
	if (key_code == XK_h && info->player_x - 5 > 0)
		info->player_x -= 5;
	if (key_code == XK_j && info->player_y + 5 < WIN_HEIGHT)
		info->player_y += 5;
	if (key_code == XK_l && info->player_x + 5 < WIN_WIDTH)
		info->player_x += 5;

	mlx_destroy_image(mlx->display, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	mlx_draw_map(mlx, info);
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
