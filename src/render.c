/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:34:51 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/15 14:21:01 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <strings.h>
#include "../includes/draw.h"
#include "../includes/types.h"
#include "../includes/textures.h"
#include "../includes/maths.h"
#include "../includes/animation.h"
#include "../includes/minimap.h"

static void	place_textures(t_prog *prog, int currentColumn)
{
	t_tex		*tex;
	int			y;

	tex = &prog->info->texs[prog->assets->tex_idx];
	prog->assets->tex = (int)(prog->assets->wall_x * (double)(tex->width));
	prog->assets->step = 1.0 * tex->height / (double)prog->assets->line_height;
	prog->assets->tex_pos = (double)(prog->assets->draw_start
			- (double)WIN_HEIGHT / 2 + (double)prog->assets->line_height / 2)
		* prog->assets->step;
	y = prog->assets->draw_start;
	while (y < prog->assets->draw_end)
	{
		prog->assets->tey = (int)prog->assets->tex_pos;
		if (prog->assets->tey < 0)
			prog->assets->tey = 0;
		if (prog->assets->tey >= tex->height)
			prog->assets->tey = tex->height - 1;
		prog->assets->tex_pos += prog->assets->step;
		prog->assets->color = textures_get_pixel(tex,
				prog->assets->tex, prog->assets->tey);
		if (prog->assets->side == 0)
			prog->assets->color = ((prog->assets->color >> 1) & 0X7F7F7F);
		put_pixel(prog->mlx, currentColumn, y, prog->assets->color);
		y += 1;
	}
}

static void	draw_floor_ceiling(t_prog *prog, int currentColumn)
{
	t_assets	*assets;
	t_info		*info;
	t_mlx		*mlx;
	t_line		line;

	info = prog->info;
	assets = prog->assets;
	mlx = prog->mlx;
	assets->floor = rgb_merge(info->floor_colors[0],
			info->floor_colors[1], info->floor_colors[2]);
	assets->ceiling = rgb_merge(info->ceiling_colors[0],
			info->ceiling_colors[1], info->ceiling_colors[2]);
	line.color = assets->ceiling;
	line.draw_start = 0;
	line.draw_end = assets->draw_start;
	draw_vert_line(mlx, currentColumn, line);
	line.color = assets->floor;
	line.draw_start = assets->draw_end;
	line.draw_end = WIN_WIDTH - 1;
	draw_vert_line(mlx, currentColumn, line);
}

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

static void	ray_cast(t_prog *p)
{
	int	x;
	int	px;
	int	py;

	x = 0;
	if (DEBUG_MODE)
	{
		px = p->info->player->posx;
		py = p->info->player->posy;
		printf("PX=[%d] | PY=[%d]\n", px, py);
		printf("MapX=[%d] | MapY=[%d]\n", p->assets->mapx, p->assets->mapy);
		printf("----------------------\n");
	}
	while (x < WIN_WIDTH)
	{
		ft_bzero(p->assets, sizeof(*p->assets));
		calculate_ray_postion(p, x);
		setting_steps(p);
		performe_dda(p);
		calculate_vert_line(p);
		place_textures(p, x);
		draw_floor_ceiling(p, x);
		x += 1;
	}
}

int	render(t_prog *p)
{
	ray_cast(p);
	p->is_running = (p->keys[XK_w] || p->keys[XK_a]
			|| p->keys[XK_s] || p->keys[XK_d]);
	if (p->is_attacking)
	{
		render_animation(p, 0, -1, ATTACK);
		if (!p->attack_anim.current_frame && !p->attack_anim.delay_counter)
			p->is_attacking = false;
	}
	else if (p->is_running)
		render_animation(p, 0, -1, RUN);
	else
		render_animation(p, 0, -1, STAND);
	mini_map(p);
	return (0);
}
