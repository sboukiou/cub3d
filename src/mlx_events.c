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

int track_door(t_door *door, int p_x, int p_y, int n_d, int *d_pos)
{
	for (int i = 0; i < n_d; i++)
	{
		if (door[i].x == p_x && door[i].y == p_y)
			return (*d_pos = i, 1);
	}
	return (0);
}

void open_door(char **map, t_door **door, int p_x, int p_y, int n_d)
{
	int d_pos;

	d_pos = -1;
	if (track_door(*door, p_x + 1, p_y, n_d, &d_pos))
	{
		if ((*door)[d_pos].is_open)
		{
			(*door)[d_pos].is_open = false;
			map[p_y][p_x + 1] = 'D';
		}
		else
		{
			(*door)[d_pos].is_open = true;
			map[p_y][p_x + 1] = '0';
		}
	}
	else if (track_door(*door, p_x - 1, p_y, n_d, &d_pos))
	{
		if ((*door)[d_pos].is_open)
		{
			(*door)[d_pos].is_open = false;
			map[p_y][p_x - 1] = 'D';
		}
		else
		{
			(*door)[d_pos].is_open = true;
			map[p_y][p_x - 1] = '0';
		}
	}	
	else if (track_door(*door, p_x, p_y + 1, n_d, &d_pos))
	{
		if ((*door)[d_pos].is_open)
		{
			(*door)[d_pos].is_open = false;
			map[p_y + 1][p_x] = 'D';
		}
		else
		{
			(*door)[d_pos].is_open = true;
			map[p_y + 1][p_x] = '0';
		}
	}	
	else if (track_door(*door, p_x, p_y - 1, n_d, &d_pos))
	{
		if ((*door)[d_pos].is_open)
		{
			(*door)[d_pos].is_open = false;
			map[p_y - 1][p_x] = 'D';
		}
		else
		{
			(*door)[d_pos].is_open = true;
			map[p_y - 1][p_x] = '0';
		}
	}
}

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
		mlx_destroy_image(mlx->display, mlx->draw_image.img);
		mlx_destroy_image(mlx->display, mlx->player_image);
		mlx_destroy_image(mlx->display, mlx->floor_image);
		mlx_destroy_image(mlx->display, mlx->wall_image);
		mlx_destroy_window(mlx->display, mlx->window);
		mlx_destroy_display(mlx->display);
		free(info->map);
		free(mlx->display);
		exit(0);
	}
	if (key_code == XK_w && info->map[info->player_y - 1][info->player_x] != 'D'
			&& info->map[info->player_y - 1][info->player_x] != '1')
		info->player_y -= 1;
	if (key_code == XK_a && info->map[info->player_y][info->player_x - 1] != 'D'
			&& info->map[info->player_y][info->player_x - 1] != '1')
		info->player_x -= 1;
	if (key_code == XK_s && info->map[info->player_y + 1][info->player_x] != 'D'
			&& info->map[info->player_y + 1][info->player_x] != '1')
		info->player_y += 1;
	if (key_code == XK_d && info->map[info->player_y][info->player_x + 1] != 'D'
			&& info->map[info->player_y][info->player_x + 1] != '1')
		info->player_x += 1;
	if (key_code == KEY_E)
		open_door(info->map, &info->door, info->player_x, info->player_y, info->n_doors);
	
	mlx_draw_minimap(mlx, info);
	/*mlx_put_image_to_window(mlx->display, mlx->window, mlx->floor_image, info->player_x * SIZE_SCALE, info->player_y * SIZE_SCALE);*/
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->player_image, info->player_x * SIZE_SCALE, info->player_y * SIZE_SCALE);
	return (0);
}

int	ft_exit(t_mlx *mlx)
{
	printf("Called ft_exit\n");
	mlx_destroy_image(mlx->display, mlx->draw_image.img);
	mlx_destroy_window(mlx->display, mlx->window);
	mlx_destroy_display(mlx->display);
	free(mlx->display);
	exit(0);
}
