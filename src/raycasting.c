/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:31:53 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 23:43:12 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <strings.h>
#include "../includes/types.h"
#include "../includes/maths.h"

void	calculate_ray_postion(t_prog *prog, int currentColumn)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	assets->camerax = 2 * currentColumn / (double)WIN_WIDTH - 1;
	assets->ray_dirx = info->player->dirx
		+ info->player->planex * assets->camerax;
	assets->ray_diry = info->player->diry
		+ info->player->planey * assets->camerax;
	assets->mapx = (int)(info->player->posx);
	assets->mapy = (int)(info->player->posy);
	if (assets->ray_dirx == 0)
		assets->delta_distx = 1e30;
	else
		assets->delta_distx = fabs(1 / assets->ray_dirx);
	if (assets->ray_diry == 0)
		assets->delta_disty = 1e30;
	else
		assets->delta_disty = fabs(1 / assets->ray_diry);
}

void	setting_steps(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	if (assets->ray_dirx < 0)
	{
		assets->stepx = -1;
		assets->side_distx = (info->player->posx - assets->mapx)
			* assets->delta_distx;
	}
	else
	{
		assets->stepx = 1;
		assets->side_distx = (assets->mapx + 1.0 - info->player->posx)
			* assets->delta_distx;
	}
	if (assets->ray_diry < 0)
	{
		assets->stepy = -1;
		assets->side_disty = (info->player->posy - assets->mapy)
			* assets->delta_disty;
	}
	else
	{
		assets->stepy = 1;
		assets->side_disty = (assets->mapy + 1.0 - info->player->posy)
			* assets->delta_disty;
	}
}

void	performe_dda(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	while (assets->hit == 0)
	{
		if (assets->side_distx < assets->side_disty)
		{
			assets->side_distx += assets->delta_distx;
			assets->mapx += assets->stepx;
			assets->side = 0;
		}
		else
		{
			assets->side_disty += assets->delta_disty;
			assets->mapy += assets->stepy;
			assets->side = 1;
		}
		if (info->map[assets->mapy][assets->mapx] == '1')
			assets->hit = 1;
		if (info->map[assets->mapy][assets->mapx] == 'D')
			assets->hit = 2;
	}
	if (assets->side == 0)
		assets->perp_wall_dist = (assets->side_distx - assets->delta_distx);
	else
		assets->perp_wall_dist = (assets->side_disty - assets->delta_disty);
}

void	calculate_vert_line(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	assets->line_height = (int)(WIN_HEIGHT / assets->perp_wall_dist);
	assets->draw_start = -assets->line_height / 2 + WIN_HEIGHT / 2;
	assets->draw_end = assets->line_height / 2 + WIN_HEIGHT / 2;
	if (assets->draw_start < 0)
		assets->draw_start = 0;
	if (assets->draw_end >= WIN_HEIGHT)
		assets->draw_end = WIN_HEIGHT - 1;
	if (assets->side == 0)
		assets->wall_x = info->player->posy
			+ assets->perp_wall_dist * assets->ray_diry;
	else
		assets->wall_x = info->player->posx
			+ assets->perp_wall_dist * assets->ray_dirx;
	assets->wall_x -= floor(assets->wall_x);
	if (assets->side == 0)
	{
		if (assets->ray_dirx > 0)
			assets->tex_idx = LT_WEST;
		else
			assets->tex_idx = LT_EAST;
	}
	else
	{
		if (assets->ray_diry > 0)
			assets->tex_idx = LT_NORTH;
		else
			assets->tex_idx = LT_SOUTH;
	}
	if (assets->hit == 2)
		assets->tex_idx = LT_DOOR;
}
