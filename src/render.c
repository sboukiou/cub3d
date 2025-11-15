#include <math.h>
#include <stdbool.h>
#include <strings.h>
#include "../includes/draw.h"
#include "../includes/types.h"
#include "../includes/textures.h"


int render(t_prog *prog)
{
  t_mlx		*mlx;
  t_info	*info;

  mlx = prog->mlx;
  info = prog->info;
    for(int x = 0; x < WIN_WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)WIN_WIDTH - 1; //x-coordinate in camera space
      double rayDirX = info->player->dirX + info->player->planeX * cameraX;
      double rayDirY = info->player->dirY + info->player->planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)(info->player->posX);
      int mapY = (int)(info->player->posY);

      /*length of ray from current position to next x or y-side*/
      double sideDistX;
      double sideDistY;

	  /*Length of the ray part for each move (x, x + 1) or (y, y + 1)*/
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (info->player->posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - info->player->posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (info->player->posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - info->player->posY) * deltaDistY;
      }
      //perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
		if(info->map[mapY][mapX] == '1')
			hit = 1;
      }
      if(side == 0)
		  perpWallDist = (sideDistX - deltaDistX);
      else
		  perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
      int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
      if(drawStart < 0)
		  drawStart = 0;
      if(drawEnd >= WIN_HEIGHT)
		  drawEnd = WIN_HEIGHT - 1;

      //choose wall color
	  double wallX;
	  if (side == 0)
		  wallX = info->player->posY + perpWallDist * rayDirY;
	  else
		  wallX = info->player->posX + perpWallDist * rayDirX;
	  wallX -= floor(wallX);
	  int	tex_idx;
	  if (side == 0)
		  tex_idx = (rayDirX > 0) ? LT_WEST: LT_EAST;
	  else
		  tex_idx = (rayDirY > 0) ? LT_NORTH: LT_SOUTH;
	  t_tex *tex = &info->texs[tex_idx];
	  int	texX = (int)(wallX * (double)(tex->width));
	  double step = 1.0 * tex->height / (double)lineHeight;
	  double texPos = (double)(drawStart - (double)WIN_HEIGHT / 2 + (double)lineHeight / 2) * step;
	  for (int y = drawStart; y < drawEnd; ++y)
	  {
		  int texY = (int)texPos;
		  if (texY < 0)
			  texY = 0;
		  if (texY >= tex->height)
			  texY = tex->height - 1;
		  texPos += step;
		  unsigned int color = textures_get_pixel(tex, texX, texY);
		  if (side == 0)
			  color = ((color >> 1) & 0X7F7F7F);
		  put_pixel(mlx, x, y , color);
	  }
	  /*   int color;*/
	  /*   switch(info->map[mapY][mapX])*/
	  /*   {*/
	  /*     case '1':  color = 0XAA4A44;  break; //red*/
	  /*     case '0':  color = 0XB09C17;  break; //yellow*/
	  /*     default: color = 0X1A8FC9; break; //cyan*/
	  /*   }*/
	  /**/
	  /*if (side == 1)*/
	  /* color /= 2;*/
	  /**/
	  /**/
	  /*   //draw the pixels of the stripe as a vertical line*/
	  /*   draw_vert_line(mlx, x, 0, drawStart, 0X1A8FC9);*/
	  /*   draw_vert_line(mlx, x, drawStart, drawEnd, color);*/
	  /*   draw_vert_line(mlx, x, drawEnd, WIN_WIDTH - 1, 0XB09C17);*/
    }
	return (0);
}
