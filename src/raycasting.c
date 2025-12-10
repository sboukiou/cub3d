/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:31:53 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/11 00:39:15 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <strings.h>
#include "../includes/types.h"
#include "../includes/maths.h"

void	set_ray_dirx(t_info *info, t_assets *assets)
{
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
}

void	setting_steps(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	set_ray_dirx(info, assets);
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
	while (prog->assets->hit == 0)
	{
		if (prog->assets->side_distx < prog->assets->side_disty)
		{
			prog->assets->side_distx += prog->assets->delta_distx;
			prog->assets->mapx += prog->assets->stepx;
			prog->assets->side = 0;
		}
		else
		{
			prog->assets->side_disty += prog->assets->delta_disty;
			prog->assets->mapy += prog->assets->stepy;
			prog->assets->side = 1;
		}
		if (prog->info->map[prog->assets->mapy][prog->assets->mapx] == '1')
			prog->assets->hit = 1;
		if (prog->info->map[prog->assets->mapy][prog->assets->mapx] == 'D')
			prog->assets->hit = 2;
	}
	if (prog->assets->side == 0)
		prog->assets->perp_wall_dist = (prog->assets->side_distx
				- prog->assets->delta_distx);
	else
		prog->assets->perp_wall_dist = (prog->assets->side_disty
				- prog->assets->delta_disty);
}

static void	vert_line_util(t_assets *assets, t_info *info)
{
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
}

void	calculate_vert_line(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	vert_line_util(assets, info);
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
