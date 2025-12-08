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
      assets->cameraX = 2 * currentColumn / (double)WIN_WIDTH - 1; //x-coordinate in camera space
      assets->rayDirX = info->player->dirX + info->player->planeX * assets->cameraX;
      assets->rayDirY = info->player->dirY + info->player->planeY * assets->cameraX;
      //which box of the map we're in
      assets->mapX = (int)(info->player->posX);
      assets->mapY = (int)(info->player->posY);


	  /*Length of the ray part for each move (x, x + 1) or (y, y + 1)*/
      assets->deltaDistX = (assets->rayDirX == 0) ? 1e30 : fabs(1 / assets->rayDirX);
      assets->deltaDistY = (assets->rayDirY == 0) ? 1e30 : fabs(1 / assets->rayDirY);

      //what direction to step in x or y-direction (either +1 or -1)

      //calculate step and initial sideDist
}

void	settingSteps(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	if(assets->rayDirX < 0)
	{
		assets->stepX = -1;
		assets->sideDistX = (info->player->posX - assets->mapX) * assets->deltaDistX;
	}
	else
	{
		assets->stepX = 1;
		assets->sideDistX = (assets->mapX + 1.0 - info->player->posX) * assets->deltaDistX;
	}
	if(assets->rayDirY < 0)
	{
		assets->stepY = -1;
		assets->sideDistY = (info->player->posY - assets->mapY) * assets->deltaDistY;
	}
	else
	{
		assets->stepY = 1;
		assets->sideDistY = (assets->mapY + 1.0 - info->player->posY) * assets->deltaDistY;
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
		if(assets->sideDistX < assets->sideDistY)
		{
			assets->sideDistX += assets->deltaDistX;
			assets->mapX += assets->stepX;
			assets->side = 0;
		}
		else
		{
			assets->sideDistY += assets->deltaDistY;
			assets->mapY += assets->stepY;
			assets->side = 1;
		}
		if(info->map[assets->mapY][assets->mapX] == '1')
			assets->hit = 1;
		if(info->map[assets->mapY][assets->mapX] == 'D')
			assets->hit = 2;
	}
	if(assets->side == 0)
		assets->perpWallDist = (assets->sideDistX - assets->deltaDistX);
	else
		assets->perpWallDist = (assets->sideDistY - assets->deltaDistY);
}

void	calculateVertLine(t_prog *prog)
{
	t_assets	*assets;
	t_info		*info;

	info = prog->info;
	assets = prog->assets;
	assets->lineHeight = (int)(WIN_HEIGHT / assets->perpWallDist);
	assets->drawStart = -assets->lineHeight / 2 + WIN_HEIGHT / 2;
	assets->drawEnd = assets->lineHeight / 2 + WIN_HEIGHT / 2;
	if(assets->drawStart < 0)
		assets->drawStart = 0;
	if(assets->drawEnd >= WIN_HEIGHT)
		assets->drawEnd = WIN_HEIGHT - 1;

	//choose wall color
	if (assets->side == 0)
		assets->wallX = info->player->posY + assets->perpWallDist * assets->rayDirY;
	else
		assets->wallX = info->player->posX + assets->perpWallDist * assets->rayDirX;
	assets->wallX -= floor(assets->wallX);
	if (assets->side == 0)
		assets->texIdx = (assets->rayDirX > 0) ? LT_EAST: LT_WEST;
	else
		assets->texIdx = (assets->rayDirY > 0) ? LT_SOUTH: LT_NORTH;
	if (assets->hit == 2)
		assets->texIdx = LT_DOOR;
}
