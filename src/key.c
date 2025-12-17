/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:18:52 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 20:38:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/macros.h"
#include "../includes/types.h"
#include "../includes/events.h"

int	handle_key_release(int key_code, t_prog *prog)
{
	if (prog == NULL)
		return (FAILURE);
	if (key_code >= 0 && key_code < 65536)
		prog->keys[key_code] = false;
	return (0);
}

void	handle_key_w(t_prog *prog)
{
	t_info		*info;
	t_player	*player;
	double		move_speed;

	move_speed = 0.02;
	info = prog->info;
	player = info->player;
	if (DEBUG_MODE)
		printf("BEFORE: pDX=[%f] pDY=[%f]\n", player->posx, player->posy);
	if (info->map[(int)(player->posy)][(int)(player->posx
				+ player->dirx * move_speed)] != '1'
			&& info->map[(int)(player->posy)][(int)(player->posx
				+ player->dirx * move_speed)] != 'D')
		player->posx += player->dirx * move_speed;
	if (info->map[(int)(player->posy + player->diry
			* move_speed)][(int)player->posx] != '1'
			&& info->map[(int)(player->posy + player->diry *
				move_speed)][(int)player->posx] != 'D')
		player->posy += player->diry * move_speed;
	if (DEBUG_MODE)
		printf("AFTER: pDX=[%f] pDY=[%f]\n", player->posx, player->posy);
}

void	handle_key_s(t_prog *prog)
{
	t_info		*info;
	t_player	*player;
	double		move_speed;

	move_speed = 0.02;
	info = prog->info;
	player = info->player;
	if (info->map[(int)player->posy][(int)(player->posx
		- player->dirx * move_speed)] != '1'
			&& info->map[(int)player->posy][(int)(player->posx
				- player->dirx * move_speed)] != 'D')
		player->posx -= player->dirx * move_speed;
	if (info->map[(int)(player->posy - player->diry
			* move_speed)][(int)player->posx] != '1'
			&& info->map[(int)(player->posy - player->diry
				* move_speed)][(int)player->posx] != 'D')
		player->posy -= player->diry * move_speed;
}

void	handle_key_d(t_prog *prog)
{
	t_info		*info;
	t_player	*player;
	double		move_speed;

	move_speed = 0.02;
	info = prog->info;
	player = info->player;
	if (info->map[(int)player->posy][(int)(player->posx
		- player->diry * move_speed)] != '1'
			&& info->map[(int)player->posy][(int)(player->posx
				- player->diry * move_speed)] != 'D')
		player->posx -= player->diry * move_speed;
	if (info->map[(int)(player->posy + player->dirx
			* move_speed)][(int)player->posx] != '1'
			&& info->map[(int)(player->posy + player->dirx
				* move_speed)][(int)player->posx] != 'D')
		player->posy += player->dirx * move_speed;
}

void	handle_key_a(t_prog *prog)
{
	t_info		*info;
	t_player	*player;
	double		move_speed;

	move_speed = 0.02;
	info = prog->info;
	player = info->player;
	if (info->map[(int)player->posy][(int)(player->posx
		+ player->diry * move_speed)] != '1'
			&& info->map[(int)player->posy][(int)(player->posx
				+ player->diry * move_speed)] != 'D')
		player->posx += player->diry * move_speed;
	if (info->map[(int)(player->posy - player->dirx
			* move_speed)][(int)player->posx] != '1'
			&& info->map[(int)(player->posy - player->dirx
				* move_speed)][(int)player->posx] != 'D')
		player->posy -= player->dirx * move_speed;
}
