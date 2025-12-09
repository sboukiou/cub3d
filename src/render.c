/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:34:51 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:39:37 by sboukiou         ###   ########.fr       */
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


static void	placeTextures(t_prog *prog, int currentColumn)
{
	t_assets	*assets;
	t_info		*info;
	t_mlx		*mlx;

	info = prog->info;
	assets = prog->assets;
	mlx = prog->mlx;
	t_tex *tex = &info->texs[assets->tex_idx];
	assets->tex = (int)(assets->wall_x * (double)(tex->width));
	assets->step = 1.0 * tex->height / (double)assets->line_height;
	assets->tex_pos = (double)(assets->draw_start - (double)WIN_HEIGHT / 2 + (double)assets->line_height / 2) * assets->step;
	for (int y = assets->draw_start; y < assets->draw_end; ++y)
	{
		assets->tey = (int)assets->tex_pos;
		if (assets->tey < 0)
			assets->tey = 0;
		if (assets->tey >= tex->height)
			assets->tey = tex->height - 1;
		assets->tex_pos += assets->step;
		assets->color = textures_get_pixel(tex, assets->tex, assets->tey);
		if (assets->side == 0)
			assets->color = ((assets->color >> 1) & 0X7F7F7F);
		put_pixel(mlx, currentColumn, y , assets->color);
	}
}

static void	drawFloorCeiling(t_prog *prog, int currentColumn)
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

int render(t_prog *prog)
{
	t_mlx		*mlx;
	t_info	*info;

	mlx = prog->mlx;
	info = prog->info;
	for (int x = 0; x < WIN_WIDTH; x += 1)
	{
		ft_bzero(prog->assets, sizeof(*prog->assets));
		calculateRayPostion(prog, x);
		settingSteps(prog);
		performeDDA(prog);
		calculateVertLine(prog);
		placeTextures(prog, x);
		drawFloorCeiling(prog, x);
	}
	prog->is_running = (prog->keys[XK_w] || prog->keys[XK_a] 
			|| prog->keys[XK_s] || prog->keys[XK_d]);
	if (prog->is_attacking)
	{
		render_animation(prog, 0, -1, ATTACK);
		if (prog->attack_anim.current_frame == 0 && prog->attack_anim.delay_counter == 0)
			prog->is_attacking = false;
	}
	else if (prog->is_running)
		render_animation(prog, 0, -1, RUN);
	else
		render_animation(prog, 0, -1, STAND);
	/*cast_ray(prog);*/
	miniMap(prog);
	return (0);
}
