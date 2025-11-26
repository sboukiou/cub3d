/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:34:51 by sboukiou          #+#    #+#             */
/*   Updated: 2025/11/24 16:34:52 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <strings.h>
#include "../includes/draw.h"
#include "../includes/types.h"
#include "../includes/textures.h"
#include "../includes/maths.h"


static void	placeTextures(t_prog *prog, int currentColumn)
{
	t_assets	*assets;
	t_info		*info;
	t_mlx		*mlx;

	info = prog->info;
	assets = prog->assets;
	mlx = prog->mlx;
	t_tex *tex = &info->texs[assets->texIdx];
	assets->teX = (int)(assets->wallX * (double)(tex->width));
	assets->step = 1.0 * tex->height / (double)assets->lineHeight;
	assets->texPos = (double)(assets->drawStart - (double)WIN_HEIGHT / 2 + (double)assets->lineHeight / 2) * assets->step;
	for (int y = assets->drawStart; y < assets->drawEnd; ++y)
	{
		assets->teY = (int)assets->texPos;
		if (assets->teY < 0)
			assets->teY = 0;
		if (assets->teY >= tex->height)
			assets->teY = tex->height - 1;
		assets->texPos += assets->step;
		assets->color = textures_get_pixel(tex, assets->teX, assets->teY);
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

	info = prog->info;
	assets = prog->assets;
	mlx = prog->mlx;
	  assets->floor = rgb_merge(info->floor_colors[0],
			  info->floor_colors[1], info->floor_colors[2]);
	  assets->ceiling = rgb_merge(info->ceiling_colors[0],
			  info->ceiling_colors[1], info->ceiling_colors[2]);
	     draw_vert_line(mlx, currentColumn, 0, assets->drawStart, assets->ceiling);
	     draw_vert_line(mlx, currentColumn, assets->drawEnd, WIN_WIDTH - 1, assets->floor);
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
  cast_ray(prog);
	return (0);
}
