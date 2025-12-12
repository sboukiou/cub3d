/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:38:11 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 20:38:13 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/types.h"
#include "../includes/events.h"

int	mouse_move(int x, t_prog *prog)
{
	int	delta_x;

	delta_x = x - WIN_WIDTH / 2;
	if (delta_x == 0)
		return (0);
	rotate_player(prog->player, delta_x * 0.0002);
	mlx_mouse_move(prog->mlx->display,
		prog->mlx->window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
