#include <mlx.h>
#include "../includes/macros.h"
#include "../includes/types.h"

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
void	rotate_player(t_player *player, double angle)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = player->dirx;
	player->dirx = player->dirx * cos(angle) - player->diry * sin(angle);
	player->diry = oldDirX * sin(angle) + player->diry * cos(angle);
	oldPlaneX = player->planex;
	player->planex = player->planex * cos(angle) - player->planey * sin(angle);
	player->planey = oldPlaneX * sin(angle) + player->planey * cos(angle);
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
		if (info->map[(int)(player->posy)][(int)(player->posx + player->dirx * moveSpeed)] != '1' && info->map[(int)(player->posy)][(int)(player->posx + player->dirx * moveSpeed)] != 'D')
			player->posx += player->dirx * moveSpeed;
		if (info->map[(int)(player->posy + player->diry * moveSpeed)][(int)player->posx] != '1' && info->map[(int)(player->posy + player->diry * moveSpeed)][(int)player->posx] != 'D')
			player->posy += player->diry * moveSpeed;
	}
	if (prog->keys[XK_s])
	{
		if (info->map[(int)player->posy][(int)(player->posx - player->dirx * moveSpeed)] != '1' && info->map[(int)player->posy][(int)(player->posx - player->dirx * moveSpeed)] != 'D')
			player->posx -= player->dirx * moveSpeed;
		if (info->map[(int)(player->posy - player->diry * moveSpeed)][(int)player->posx] != '1' && info->map[(int)(player->posy - player->diry * moveSpeed)][(int)player->posx] != 'D')
			player->posy -= player->diry * moveSpeed;
	}
	if (prog->keys[XK_d])
	{
		if (info->map[(int)player->posy][(int)(player->posx - player->diry * moveSpeed)] != '1' && info->map[(int)player->posy][(int)(player->posx - player->diry * moveSpeed)] != 'D')
			player->posx -= player->diry * moveSpeed;
		if (info->map[(int)(player->posy + player->dirx * moveSpeed)][(int)player->posx] != '1' && info->map[(int)(player->posy + player->dirx * moveSpeed)][(int)player->posx] != 'D')
			player->posy += player->dirx * moveSpeed;
	}
	if (prog->keys[XK_a])
	{
		if (info->map[(int)player->posy][(int)(player->posx + player->diry * moveSpeed)] != '1' && info->map[(int)player->posy][(int)(player->posx + player->diry * moveSpeed)] != 'D')
			player->posx += player->diry * moveSpeed;
		if (info->map[(int)(player->posy - player->dirx * moveSpeed)][(int)player->posx] != '1' && info->map[(int)(player->posy - player->dirx * moveSpeed)][(int)player->posx] != 'D')
			player->posy -= player->dirx * moveSpeed;
	}
	if (prog->keys[XK_Right])
		rotate_player(player, rotSpeed);
	if (prog->keys[XK_Left])
		rotate_player(player, -rotSpeed);
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
		int y = prog->player->posy + prog->player->diry * 1.5;
		int x = prog->player->posx + prog->player->dirx * 1.5;
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

int mouse_move(int x, int y, t_prog *prog)
{
	int delta_x;

	delta_x = x - WIN_WIDTH / 2;
	if (delta_x == 0)
		return (0);
	rotate_player(prog->player, delta_x * 0.0002);
	mlx_mouse_move(prog->mlx->display, prog->mlx->window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
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
