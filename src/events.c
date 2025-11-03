#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
 #include "../includes/game.h" 
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
	t_player *player;
	int		px;
	int		py;
	double	moveSpeed = 0.1;
	double	rotSpeed = 0.03;

	info = prog->info;
	px = info->player->posX;
	py = info->player->posY;
	mlx = prog->mlx;
	player = info->player;
	/*Handle moving directions*/
    if(key_code == XK_w)
    {
		if(info->map[(int)(player->posY)][(int)(player->posX + player->dirX * moveSpeed)]
				!= '1')
			player->posX += player->dirX * moveSpeed;
		if(info->map[(int)(player->posY + player->dirY * moveSpeed)][(int)player->posX]
				!= '1')
			player->posY += player->dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(key_code == XK_s)
    {
      if(info->map[(int)player->posY][(int)(player->posX - player->dirX * moveSpeed)]
			  != '1')
		  player->posX -= player->dirX * moveSpeed;
      if(info->map[(int)(player->posY - player->dirY * moveSpeed)][(int)player->posX]
			  != '1')
		  player->posY -= player->dirY * moveSpeed;
    }
    //rotate to the right
    if(key_code == XK_Right)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = player->dirX;
      player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
      player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
      double oldPlaneX = player->planeX;
      player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
      player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(key_code == XK_Left)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = player->dirX;
      player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
      player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
      double oldPlaneX = player->planeX;
      player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
      player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
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
