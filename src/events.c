/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:10:44 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/15 14:13:24 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/macros.h"
#include "../includes/types.h"
#include "../lib/libft/libft.h"
#include "../includes/events.h"
#include "../includes/animation.h"

void	destroy_program(t_prog *prog)
{
	t_mlx	*mlx;
	int		i;

	i = -1;
	mlx = prog->mlx;
	free_animation(&prog->run_anim, prog->mlx->display);
	free_animation(&prog->stand_anim, prog->mlx->display);
	free_animation(&prog->attack_anim, prog->mlx->display);
	if (mlx && mlx->display && mlx->draw_image.img)
		mlx_destroy_image(mlx->display, mlx->draw_image.img);
	if (mlx && mlx->display && mlx->player_image)
		mlx_destroy_image(mlx->display, mlx->player_image);
	if (mlx && mlx->display && mlx->floor_image)
		mlx_destroy_image(mlx->display, mlx->floor_image);
	if (mlx && mlx->display && mlx->wall_image)
		mlx_destroy_image(mlx->display, mlx->wall_image);
	while (prog && prog->info && ++i < TEX_COUNT)
	{
		if (!prog->info->texs[i].img)
			break ;
		mlx_destroy_image(mlx->display, prog->info->texs[i].img);
	}
	ft_exit(prog->mlx);
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dirx;
	player->dirx = player->dirx * cos(angle) - player->diry * sin(angle);
	player->diry = old_dir_x * sin(angle) + player->diry * cos(angle);
	old_plane_x = player->planex;
	player->planex = player->planex * cos(angle) - player->planey * sin(angle);
	player->planey = old_plane_x * sin(angle) + player->planey * cos(angle);
}

void	move_player(t_prog *prog)
{
	t_info		*info;
	t_player	*player;

	info = prog->info;
	player = info->player;
	if (player->posx == (int)player->posx || player->posy == (int)player->posy)
	{
		if (info->map[(int)player->posy][(int)player->posx])
			player->posx += 0.3;
		if (info->map[(int)player->posy])
			player->posy += 0.03;
		return ;
	}
	if (prog->keys[XK_w])
		handle_key_w(prog);
	if (prog->keys[XK_s])
		handle_key_s(prog);
	if (prog->keys[XK_d])
		handle_key_d(prog);
	if (prog->keys[XK_a])
		handle_key_a(prog);
	if (prog->keys[XK_Right])
		rotate_player(player, ROT_SPEED);
	if (prog->keys[XK_Left])
		rotate_player(player, -ROT_SPEED);
}

int	handle_key_press(int key_code, t_prog *prog)
{
	int	y;
	int	x;

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
		y = prog->player->posy + prog->player->diry * 1.5;
		x = prog->player->posx + prog->player->dirx * 1.5;
		if (prog->info->map[y][x] == 'D')
			prog->info->map[y][x] = 'd';
		else if (prog->info->map[y][x] == 'd')
			prog->info->map[y][x] = 'D';
	}
	return (0);
}

int	ft_exit(t_mlx *mlx)
{
	if (mlx && mlx->window)
		mlx_destroy_window(mlx->display, mlx->window);
	if (mlx && mlx->display)
	{
		mlx_destroy_display(mlx->display);
		free(mlx->display);
	}
	ft_calloc(0, 0, 0);
	ft_malloc(0, 0);
	exit(0);
}
