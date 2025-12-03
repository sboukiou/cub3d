#include "../lib/mlx_linux/mlx.h"
#include "../includes/macros.h"
 #include "../includes/game.h" 
#include "../includes/types.h"
#include "../includes/animation.h"
/**
	* handle_key - Check if a given key is the escape
	* @key_code: The number corresponding to the key
	* @data: Info about the mlx and mlx_window ptrs
	* @Return: 0 , Or quit berfore if it's ESC
	*/

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

void	move_player(t_prog *prog)
{
	t_info		*info;
	t_player	*player;
	double		moveSpeed;
	double		rotSpeed;

	moveSpeed = 0.02;
	rotSpeed = 0.03;
	info = prog->info;
	player = info->player;
	if (prog->keys[XK_w])
	{
		if (info->map[(int)(player->posY)][(int)(player->posX + player->dirX * moveSpeed)] != '1' && info->map[(int)(player->posY)][(int)(player->posX + player->dirX * moveSpeed)] != 'D')
			player->posX += player->dirX * moveSpeed;
		if (info->map[(int)(player->posY + player->dirY * moveSpeed)][(int)player->posX] != '1' && info->map[(int)(player->posY + player->dirY * moveSpeed)][(int)player->posX] != 'D')
			player->posY += player->dirY * moveSpeed;
	}
	if (prog->keys[XK_s])
	{
		if (info->map[(int)player->posY][(int)(player->posX - player->dirX * moveSpeed)] != '1' && info->map[(int)player->posY][(int)(player->posX - player->dirX * moveSpeed)] != 'D')
			player->posX -= player->dirX * moveSpeed;
		if (info->map[(int)(player->posY - player->dirY * moveSpeed)][(int)player->posX] != '1' && info->map[(int)(player->posY - player->dirY * moveSpeed)][(int)player->posX] != 'D')
			player->posY -= player->dirY * moveSpeed;
	}
	if (prog->keys[XK_d])
	{
		if (info->map[(int)player->posY][(int)(player->posX - player->dirY * moveSpeed)] != '1' && info->map[(int)player->posY][(int)(player->posX - player->dirY * moveSpeed)] != 'D')
			player->posX -= player->dirY * moveSpeed;
		if (info->map[(int)(player->posY + player->dirX * moveSpeed)][(int)player->posX] != '1' && info->map[(int)(player->posY + player->dirX * moveSpeed)][(int)player->posX] != 'D')
			player->posY += player->dirX * moveSpeed;
	}
	if (prog->keys[XK_a])
	{
		if (info->map[(int)player->posY][(int)(player->posX + player->dirY * moveSpeed)] != '1' && info->map[(int)player->posY][(int)(player->posX + player->dirY * moveSpeed)] != 'D')
			player->posX += player->dirY * moveSpeed;
		if (info->map[(int)(player->posY - player->dirX * moveSpeed)][(int)player->posX] != '1' && info->map[(int)(player->posY - player->dirX * moveSpeed)][(int)player->posX] != 'D')
			player->posY -= player->dirX * moveSpeed;
	}
	if (prog->keys[XK_Right])
	{
		double oldDirX = player->dirX;
		player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
		player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
		double oldPlaneX = player->planeX;
		player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
		player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
	}
	if (prog->keys[XK_Left])
	{
		double oldDirX = player->dirX;
		player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
		player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
		double oldPlaneX = player->planeX;
		player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
		player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
	}
}

int	handle_key_press(int key_code, t_prog *prog)
{
	if (prog == NULL)
		return (FAILURE);
	if (key_code == ESCAPE)
		destroy_program(prog);
	if (key_code >= 0 && key_code < 65536)
		prog->keys[key_code] = true;
	if (key_code == KEY_F && !prog->is_attacking)
	{
		prog->is_attacking = true;
		prog->attack_anim.current_frame = 0;
		prog->attack_anim.delay_counter = 0;
	}
	if (key_code == KEY_E)
	{
		int y = prog->player->posY + prog->player->dirY * 1.5;
		int x = prog->player->posX + prog->player->dirX * 1.5;
		if (prog->info->map[y][x] == 'D')
			prog->info->map[y][x] = 'd';
		else if (prog->info->map[y][x] == 'd')
			prog->info->map[y][x] = 'D';
	}
	return (0);
}

int	handle_key_release(int key_code, t_prog *prog)
{
	if (prog == NULL)
		return (FAILURE);
	if (key_code >= 0 && key_code < 65536)
		prog->keys[key_code] = false;
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
