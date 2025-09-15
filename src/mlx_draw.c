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

int mlx_draw_minimap(t_mlx *mlx, t_info *info)
{
	if (info == NULL || mlx == NULL)
		return (FAILURE);


	info->map_width *= SIZE_SCALE;
	info->map_height *= SIZE_SCALE;

	mlx->player_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_Player_Big.xpm",
		&info->map_width, &info->map_height);
	mlx->wall_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_Wall_Big.xpm",
			&info->map_width, &info->map_height);
	mlx->floor_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_Floor_Big.xpm",
			&info->map_width, &info->map_height);
	mlx->door_image = mlx_xpm_file_to_image(mlx->display, "./textures/minimap/Castle/Castle_door.xpm",
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
			else if (map[y][x] == 'D')
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->door_image, x * SIZE_SCALE, y * SIZE_SCALE);
			else if (map[y][x] == 'N')
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->player_image, x * SIZE_SCALE, y * SIZE_SCALE);
			else if (x != info->player_x || y != info->player_y)
				mlx_put_image_to_window(mlx->display, mlx->window, mlx->floor_image, x * SIZE_SCALE, y * SIZE_SCALE);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

bool	mlx_draw_square(t_mlx *mlx, int x, int y, int color, int size)
{
	if (mlx == NULL)
		return (false);

	if (size > 10)
		size = size - 4;
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			if ( i == y || i == y + size - 1 || j == x || j == x + size - 1)
				put_pixel(mlx, j, i, color);
	return (true);
}

void draw_line(t_mlx *mlx, int x, int y, double dx, double dy, int color)
{
    t_mlx_img *img = &mlx->draw_image;
    double len = 32.0;
    double norm = sqrt(dx * dx + dy * dy);
    double step_x = (dx / norm);
    double step_y = (dy / norm);

    for (int i = 0; i < (int)len; i++)
    {
        int px = x + (int)(step_x * i);
        int py = y + (int)(step_y * i);

        char *dst = img->addr + (py * img->llen + px * (img->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void draw_ray_to_wall(t_mlx *mlx, t_info *info, double px, double py, double dir_x, double dir_y, int color)
{
    char **map = info->map;
    double ray_x = px;
    double ray_y = py;
    double step = 0.05; // Small step for accuracy
    int max_steps = 200; // Avoid infinite loop
    int hit = 0;

    for (int i = 0; i < max_steps; i++)
    {
        int map_x = (int)ray_x;
        int map_y = (int)ray_y;

        if (map[map_y] && map[map_y][map_x] == '1')
        {
            hit = 1;
            break;
        }
        ray_x += dir_x * step;
        ray_y += dir_y * step;
    }

    if (hit)
    {
        // Scale positions for minimap (use your SIZE_SCALE or equivalent)
        int start_x = (int)(px * SIZE_SCALE);
        int start_y = (int)(py * SIZE_SCALE);
        int end_x = (int)(ray_x * SIZE_SCALE);
        int end_y = (int)(ray_y * SIZE_SCALE);

        // Draw line from player to wall hit
        double dx = end_x - start_x;
        double dy = end_y - start_y;

        // Reuse your draw_line function, or inline here:
        double len = sqrt(dx * dx + dy * dy);
        double step_x = dx / len;
        double step_y = dy / len;
        for (int i = 0; i < (int)len; i++)
        {
            int pxl_x = start_x + (int)(step_x * i);
            int pxl_y = start_y + (int)(step_y * i);
			put_pixel(mlx, pxl_x + 22, pxl_y + 22, color);
        }
    }
}
bool	mlx_draw_field(t_mlx *mlx, t_info *info)
{
	char **map;

	mlx->draw_image.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->draw_image.img == NULL)
		return (printf("Filed to create field image\n"), false);
	mlx->draw_image.addr = mlx_get_data_addr(mlx->draw_image.img, &mlx->draw_image.bpp, &mlx->draw_image.llen, &mlx->draw_image.endian);
	if (mlx == NULL || info == NULL)
		return (false);
	map = info->map;
	for (int i = 0; map[i]; i++)
		for (int j = 0; map[i][j]; j++)
			if (map[i][j] == '1')
				mlx_draw_square(mlx, j * SIZE_SCALE, i * SIZE_SCALE, WHITE, 50);
	mlx_draw_square(mlx, info->player_x * SIZE_SCALE + 22, info->player_y * SIZE_SCALE + 22, GREEN, 3);
	draw_ray_to_wall(mlx, info, info->player_x, info->player_y, info->dir_x, info->dir_y, GREEN);
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->draw_image.img, 0, 0);
	return (true);
}

