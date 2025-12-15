/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:38:11 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 17:15:03 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/types.h"
#include "../includes/events.h"

int	mouse_hide(int bottun, int x, int y, t_prog *prog)
{
	(void)x;
	(void)y;
	if (bottun == 1)
	{
		prog->no_mouse = 0;
		mlx_mouse_hide(prog->mlx->display, prog->mlx->window);
	}
	if (bottun == 3)
	{
		prog->no_mouse = 1;
		mlx_mouse_show(prog->mlx->display, prog->mlx->window);
	}
	return (0);
}

int	mouse_move(int x, int y, t_prog *prog)
{
	int	delta_x;

	(void)y;
	if (prog->no_mouse)
		return (0);
	delta_x = x - WIN_WIDTH / 2;
	if (delta_x == 0)
		return (0);
	rotate_player(prog->player, delta_x * 0.002);
	mlx_mouse_move(prog->mlx->display,
		prog->mlx->window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
