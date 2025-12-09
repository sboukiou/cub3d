#include <math.h>
#include <stdbool.h>
#include <strings.h>
#include "../includes/types.h"
#include "../includes/maths.h"

void	calculateRayPostion(t_prog *prog, int currentColumn)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
      //calculate ray position and direction
      assets->camerax = 2 * currentColumn / (double)WIN_WIDTH - 1; //x-coordinate in camera space
      assets->ray_dirx = info->player->dirx + info->player->planex * assets->camerax;
      assets->ray_diry = info->player->diry + info->player->planey * assets->camerax;
      //which box of the map we're in
      assets->mapx = (int)(info->player->posx);
      assets->mapy = (int)(info->player->posy);


	  /*Length of the ray part for each move (x, x + 1) or (y, y + 1)*/
      assets->delta_distx = (assets->ray_dirx == 0) ? 1e30 : fabs(1 / assets->ray_dirx);
      assets->delta_disty = (assets->ray_diry == 0) ? 1e30 : fabs(1 / assets->ray_diry);

      //what direction to step in x or y-direction (either +1 or -1)

      //calculate step and initial sideDist
}

void	settingSteps(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	if(assets->ray_dirx < 0)
	{
		assets->stepx = -1;
		assets->side_distx = (info->player->posx - assets->mapx) * assets->delta_distx;
	}
	else
	{
		assets->stepx = 1;
		assets->side_distx = (assets->mapx + 1.0 - info->player->posx) * assets->delta_distx;
	}
	if(assets->ray_diry < 0)
	{
		assets->stepy = -1;
		assets->side_disty = (info->player->posy - assets->mapy) * assets->delta_disty;
	}
	else
	{
		assets->stepy = 1;
		assets->side_disty = (assets->mapy + 1.0 - info->player->posy) * assets->delta_disty;
	}
}

void	performeDDA(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	while(assets->hit == 0)
	{
		if(assets->side_distx < assets->side_disty)
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
		if(info->map[assets->mapy][assets->mapx] == '1')
			assets->hit = 1;
		if(info->map[assets->mapy][assets->mapx] == 'D')
			assets->hit = 2;
	}
	if(assets->side == 0)
		assets->perp_wall_dist = (assets->side_distx - assets->delta_distx);
	else
		assets->perp_wall_dist = (assets->side_disty - assets->delta_disty);
}

void	calculateVertLine(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	assets->line_height = (int)(WIN_HEIGHT / assets->perp_wall_dist);
	assets->draw_start = -assets->line_height / 2 + WIN_HEIGHT / 2;
	assets->draw_end = assets->line_height / 2 + WIN_HEIGHT / 2;
	if(assets->draw_start < 0)
		assets->draw_start = 0;
	if(assets->draw_end >= WIN_HEIGHT)
		assets->draw_end = WIN_HEIGHT - 1;

	//choose wall color
	if (assets->side == 0)
		assets->wall_x = info->player->posy + assets->perp_wall_dist * assets->ray_diry;
	else
		assets->wall_x = info->player->posx + assets->perp_wall_dist * assets->ray_dirx;
	assets->wall_x -= floor(assets->wall_x);
	if (assets->side == 0)
		assets->tex_idx = (assets->ray_dirx > 0) ? LT_WEST: LT_EAST;
	else
		assets->tex_idx = (assets->ray_diry > 0) ? LT_NORTH: LT_SOUTH;
	if (assets->hit == 2)
		assets->tex_idx = LT_DOOR;
}
