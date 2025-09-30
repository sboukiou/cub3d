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

int	render(t_mlx *mlx, t_info *info)
{
	for (int x = 0; x < WIN_WIDTH; x++)
    {
        double camera_x = 2 * x / (double)WIN_WIDTH - 1;
        double ray_angle = info->angle + atan(camera_x * tan(FOV / 2));
        double ray_dir_x = cos(ray_angle);
        double ray_dir_y = sin(ray_angle);

        double ray_x = info->player_x;
        double ray_y = info->player_y;
        double step = 1.0;
        double distance = 0;
        while (1)
        {
            ray_x += ray_dir_x * step;
            ray_y += ray_dir_y * step;
            distance += step;
            int map_x = (int)(ray_x / SIZE_SCALE);
            int map_y = (int)(ray_y / SIZE_SCALE);
            if (info->map[map_y][map_x] == '1') break;
        }

        double corrected_dist = distance * cos(ray_angle - info->angle);
        int line_height = (int)(WIN_HEIGHT / corrected_dist);
        int draw_start = -line_height / 2 + WIN_HEIGHT / 2 - SIZE_SCALE;
        int draw_end = line_height / 2 + WIN_HEIGHT / 2 + SIZE_SCALE;
        if (draw_start < 0) draw_start = 0;
        if (draw_end >= WIN_HEIGHT) draw_end = WIN_HEIGHT - 1;

        for (int y = 0; y < draw_start; y++)
            put_pixel(mlx, x, y, LIGHT_BLUE);
        for (int y = draw_start; y < draw_end; y++)
            put_pixel(mlx, x, y, WHITE); 
        for (int y = draw_end; y < WIN_HEIGHT; y++)
            put_pixel(mlx, x, y, BROWN);
    }
	return (SUCCESS);
}
