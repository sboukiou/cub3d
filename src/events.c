#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
 #include "../includes/mlx_game_simulation.h" 
#include "../includes/types.h"
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

void	destroy_program(t_prog *prog)
{
	t_mlx	*mlx;
	t_info	*info;

	info = prog->info;
	mlx = prog->mlx;
	if (mlx->draw_image.img)
		mlx_destroy_image(mlx->display, mlx->draw_image.img);
	if (mlx->player_image)
		mlx_destroy_image(mlx->display, mlx->player_image);
	if (mlx->floor_image)
		mlx_destroy_image(mlx->display, mlx->floor_image);
	if (mlx->wall_image)
		mlx_destroy_image(mlx->display, mlx->wall_image);
	mlx_destroy_window(mlx->display, mlx->window);
	mlx_destroy_display(mlx->display);
	free(info->map);
	free(mlx->display);
	exit(0);
}

void	move_player(t_prog *prog, int key_code)
{
	t_mlx	*mlx;
	t_info	*info;
	int		px;
	int		py;
	double	move_speed = 2;
	double	next_x;
	double	next_y;

	info = prog->info;
	px = info->player_x;
	py = info->player_y;
	mlx = prog->mlx;
	/*Handle moving directions*/
	if (key_code == XK_w)
	{
		next_x = info->player_x + info->dir_x * move_speed;
		next_y = info->player_y + info->dir_y * move_speed;
		if(info->map[((int)next_y) / MINIMAP_SIZE_SCALE][(int)next_x / MINIMAP_SIZE_SCALE] == '1')
			return ;
		if (next_x <= 0 || next_y <= 0)
			return ;
		info->player_x = next_x;
		info->player_y = next_y;
	}
	/* Strafe left (A) */
	if (key_code == XK_d)
	{
		next_x = info->player_x - info->dir_y * move_speed;
		next_y = info->player_y + info->dir_x * move_speed;
		if (info->map[(int)(next_y / MINIMAP_SIZE_SCALE)][(int)(next_x / MINIMAP_SIZE_SCALE)] != '1')
		{
			info->player_x = next_x;
			info->player_y = next_y;
		}
	}

	/* Strafe right (D) */
	if (key_code == XK_a)
	{
		next_x = info->player_x + info->dir_y * move_speed;
		next_y = info->player_y - info->dir_x * move_speed;
		if (info->map[(int)(next_y / MINIMAP_SIZE_SCALE)][(int)(next_x / MINIMAP_SIZE_SCALE)] != '1')
		{
			info->player_x = next_x;
			info->player_y = next_y;
		}
	}
	if (key_code == XK_s)
	{
		next_x = info->player_x - info->dir_x * move_speed;
		next_y = info->player_y - info->dir_y * move_speed;
		if(info->map[((int)next_y) / MINIMAP_SIZE_SCALE][(int)next_x / MINIMAP_SIZE_SCALE] == '1')
			return ;
		if (next_x <= 0 || next_y <= 0)
			return ;
		info->player_x = next_x;
		info->player_y = next_y;
	}

	/*Handle rotations*/
	if (key_code == XK_Left)
		info->angle -= ROT_SPEED;
	else if (key_code == XK_Right)
		info->angle += ROT_SPEED;
	info->dir_x = cos(info->angle);
	info->dir_y = sin(info->angle);
	
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
		destroy_program(prog);
	else
		move_player(prog, key_code);
	game_layout(prog);
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
