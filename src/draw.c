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
	*(unsigned int *)dst = color;
}

int calculate_distance(int px, int py, int dx, int dy)
{
    int diff_x = dx - px;
    int diff_y = dy - py;
    double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
    return (int)distance;
}

static int	draw_line(t_mlx *mlx, t_info *info, int x, int y, double dx, double dy, int color)
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
    while (py > 0 && py < WIN_HEIGHT && info->map[py / SIZE_SCALE][px / SIZE_SCALE] != '1')
    {
		px = x + (int)(step_x * i);
		py = y + (int)(step_y * i);

		if (px > 0 && px < WIN_WIDTH)
			if (py > 0 && py < WIN_HEIGHT && info->map[py / SIZE_SCALE][px / SIZE_SCALE] != '1')
				put_pixel(mlx, px, py, color);
		i += 1;
    }
        return (SUCCESS);
}


int	draw_player(t_mlx *mlx, t_info *info)
{
	int	px;
	int	py;
	double	fov_x;
	double	fov_y;

	if (mlx == NULL || info ==  NULL)
		return (FAILURE);
	px = info->player_x;
	py = info->player_y;
	for (int i = py - 4; i < py + 4; i += 1)
		for (int j = px - 4; j < px + 4; j += 1)
		{
			if(info->map[py / SIZE_SCALE][px / SIZE_SCALE] == '1')
				return (SUCCESS);
			put_pixel(mlx, j, i, GREEN);
		}
	for (float degree = info->angle - (PI / 6); degree < info->angle + (PI / 6); degree += 0.001)
	{
		fov_x = cos(degree);
		fov_y = sin(degree);
		draw_line(mlx, info, info->player_x, info->player_y, fov_x, fov_y, WHITE);
		double distance = calculate_distance(info->player_x, info->player_y, fov_x, fov_y);
		int	line_height = (int)(WIN_HEIGHT) / distance;
		int draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0) draw_start = 0;
		int draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT) draw_end = WIN_HEIGHT - 1;
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

int	mlx_draw_field(t_mlx *mlx, t_info *info)
{
	if (mlx == NULL || info == NULL)
		return (FAILURE);
	if (mlx->draw_image.img != NULL)
		mlx_destroy_image(mlx->display, mlx->draw_image.img);
	mlx->draw_image.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->draw_image.img == NULL)
		return (FAILURE);
	mlx->draw_image.addr = mlx_get_data_addr(mlx->draw_image.img, &mlx->draw_image.bpp, &mlx->draw_image.llen, &mlx->draw_image.endian);
	for (int i = 0; info->map[i]; i++)
		for (int j = 0; info->map[i][j]; j++)
			if (info->map[i][j] == '1')
				mlx_draw_square(mlx, j * SIZE_SCALE, i * SIZE_SCALE, WHITE, 40);
	draw_player(mlx, info);

	mlx_put_image_to_window(mlx->display, mlx->window, mlx->draw_image.img, 0, 0);
	return (SUCCESS);
}


