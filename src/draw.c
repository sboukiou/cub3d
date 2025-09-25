#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
 #include "../includes/minimap_utils.h" 
#include "../includes/types.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	t_mlx_img *img;

	img = &mlx->draw_image;
	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	draw_line(t_mlx *mlx, t_info *info, int x, int y, double dx, double dy, int color)
{
		(void)color;
	if (mlx == NULL || info == NULL)
		return (FAILURE);
    double norm = sqrt(dx * dx + dy * dy);
    double step_x = (dx / norm);
    double step_y = (dy / norm);

	int i = 0;
	int px = x + (int)(step_x * i);
	int py = y + (int)(step_y * i);
    while (py > 0 && py < WIN_HEIGHT && info->map[py / MINIMAP_SIZE_SCALE][px / MINIMAP_SIZE_SCALE] != '1')
    {
		px = x + (int)(step_x * i);
		py = y + (int)(step_y * i);

		if (px > 0 && px < WIN_WIDTH)
			if (py > 0 && py < WIN_HEIGHT && info->map[py / MINIMAP_SIZE_SCALE][px / MINIMAP_SIZE_SCALE] != '1')
				put_pixel(mlx, px, py, color);
		i += 1;
    }
        return (SUCCESS);
}


bool	mlx_draw_square(t_mlx *mlx, int x, int y, int color, int size)
{
	if (mlx == NULL)
		return (false);

	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			if ( i == y || j == x + size - 1 || j == x || i == y + size - 1)
				put_pixel(mlx, j, i, color);
	return (true);
}
