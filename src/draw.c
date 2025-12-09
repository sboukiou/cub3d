/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:46:12 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:48:02 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/macros.h"
#include "../includes/animation.h"
#include "../includes/types.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char		*dst;
	t_mlx_img	*img;

	img = &mlx->draw_image;
	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	draw_vert_line(t_mlx *mlx, int x, t_line line)
{
	int		count;

	if (mlx == NULL)
		return (FAILURE);
	if (line.draw_start < 0 || line.draw_end < 0)
		return (FAILURE);
	if (line.draw_start >= WIN_HEIGHT)
		return (SUCCESS);
	count = line.draw_start;
	while (count < line.draw_end)
	{
		if (count >= WIN_HEIGHT)
			return (SUCCESS);
		put_pixel(mlx, x, count, line.color);
 		count += 1;
	}
	return (SUCCESS);
}

bool	mlx_draw_square(t_mlx *mlx, int x, int y, int size)
{
	if (mlx == NULL)
		return (false);

	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			/*if ( i == y || j == x + size - 1 || j == x || i == y + size - 1)*/
			put_pixel(mlx, j, i, 0XFFFFF0);
	return (true);
}

void	draw_pixel_scaled(t_mlx *mlx, int x, int y, unsigned int color)
{
	if (color == 0xFF000000)
		return ;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		put_pixel(mlx, x, y, color);
}
