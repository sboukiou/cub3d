#include "../includes/macros.h"
#include "../includes/types.h"
#include "../includes/draw.h"
 #include "../includes/checkers.h" 

int	draw_miniplayer(t_prog *prog)
{
	t_info	*info;
	t_mlx	*mlx;
	int	px;
	int	py;
	double	fov_x;
	double	fov_y;

	if (is_prog_valid(prog) == false)
		return (FAILURE);
	info = prog->info;
	mlx = prog->mlx;
	px = info->player_x;
	py = info->player_y;
	if(info->map[py / MINIMAP_SIZE_SCALE][px / MINIMAP_SIZE_SCALE] == '1')
		return (SUCCESS);
	for (int i = py - 2; i < py + 2; i += 1)
		for (int j = px - 2; j < px + 2; j += 1)
		{
			if(info->map[i / MINIMAP_SIZE_SCALE][j / MINIMAP_SIZE_SCALE] == '1')
				put_pixel(mlx, j, i, GREEN);
		}
	for (float degree = info->angle - (PI / 6); degree < info->angle + (PI / 6); degree += 0.001)
	{
		fov_x = cos(degree);
		fov_y = sin(degree);
		draw_line(mlx, info, info->player_x, info->player_y, fov_x, fov_y, WHITE);
	}
	return (SUCCESS);
}

int	minimap(t_prog *prog)
{
	t_mlx	*mlx;
	t_info	*info;

	if (is_prog_valid(prog) == false)
		return (FAILURE);

	mlx = prog->mlx;
	info = prog->info;
	for (int y = 0; info->map[y]; y++)
		for (int x = 0; info->map[y][x]; x++)
			if(info->map[y][x] == '1')
				mlx_draw_square(mlx, x * MINIMAP_SIZE_SCALE, y * MINIMAP_SIZE_SCALE, BLACK, 10);
	draw_miniplayer(prog);

	return (SUCCESS);
}
