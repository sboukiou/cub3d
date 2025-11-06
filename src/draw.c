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

int	draw_vert_line(t_mlx *mlx, int x, int drawStart, int drawEnd, int color)
{
	if (mlx == NULL)
		return (FAILURE);
	  if (drawStart < 0 || drawEnd < 0)
		  return (FAILURE);
	if ( drawStart >= WIN_HEIGHT)
		return (SUCCESS);
	for (int i =  drawStart; i < drawEnd; i += 1)
	{
		if (i >= WIN_HEIGHT)
			return (SUCCESS);
		put_pixel(mlx, x, i, color);
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
