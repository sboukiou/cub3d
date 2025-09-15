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
	mlx->draw_image.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->draw_image.img == NULL)
		return (FAILURE);
	mlx->draw_image.addr = mlx_get_data_addr(mlx->draw_image.img,
		&mlx->draw_image.bpp, &mlx->draw_image.llen, &mlx->draw_image.endian);
	if (mlx->draw_image.addr == NULL)
		return (FAILURE);
	mlx->player_image = NULL;
	mlx->wall_image = NULL;
	mlx->floor_image = NULL;
	return (SUCCESS);
}
