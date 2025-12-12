/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:20:50 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 23:22:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// minimap.c

#include "../includes/types.h"
#include "../includes/draw.h"
#include "../lib/libft/libft.h"

#define MM_SIZE 120
#define MM_SCALE 8
#define MM_RADIUS 6

static void	draw_tile(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			if (x + j >= 0 && x + j < MM_SIZE && y + i >= 0 && y + i < MM_SIZE)
				put_pixel(mlx, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static int	get_tile_color(char **map, int mx, int my, t_info *info)
{
	if (my < 0 || my >= info->map_height || mx < 0)
		return (0);
	if (!map[my] || mx >= (int)ft_strlen(map[my]))
		return (0);
	if (map[my][mx] == '1')
		return (0xFFFFFF);
	if (map[my][mx] == 'D')
		return (0x8B4513);
	return (0);
}

static void	draw_map_tiles(t_prog *p, int cx, int cy)
{
	int		x;
	int		y;
	int		mx;
	int		my;
	int		color;

	y = -1;
	while (++y <= MM_RADIUS * 2)
	{
		x = -1;
		while (++x <= MM_RADIUS * 2)
		{
			mx = (int)p->info->player->posx - MM_RADIUS + x;
			my = (int)p->info->player->posy - MM_RADIUS + y;
			color = get_tile_color(p->info->map, mx, my, p->info);
			if (color)
				draw_tile(p->mlx, cx + (x - MM_RADIUS) * MM_SCALE
					- (int)((p->info->player->posx - (int)p->info->player->posx)
						* MM_SCALE), cy + (y - MM_RADIUS) * MM_SCALE
					- (int)((p->info->player->posy - (int)p->info->player->posy)
						* MM_SCALE), color);
		}
	}
}

static void	draw_player(t_mlx *mlx, t_player *p, int cx, int cy)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = -3;
	while (++i <= 3)
	{
		j = -3;
		while (++j <= 3)
			put_pixel(mlx, cx + j, cy + i, 0xFF0000);
	}
	i = -1;
	while (++i < 10)
	{
		dx = cx + (int)(p->dirx * i);
		dy = cy + (int)(p->diry * i);
		if (dx >= 0 && dx < MM_SIZE && dy >= 0 && dy < MM_SIZE)
			put_pixel(mlx, dx, dy, 0xFFFF00);
	}
}

int	mini_map(t_prog *prog)
{
	int	center;

	center = MM_SIZE / 2;
	draw_map_tiles(prog, center, center);
	draw_player(prog->mlx, prog->info->player, center, center);
	return (0);
}
