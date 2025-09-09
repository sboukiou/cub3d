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
