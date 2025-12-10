/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:32:09 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 23:25:28 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/macros.h"
#include "../includes/types.h"
#include "../includes/parse_map.h"

int	mlx_init_display(t_mlx *mlx)
{
	mlx->display = mlx_init();
	if (mlx->display == NULL)
		return (FAILURE);
	mlx->window = mlx_new_window(mlx->display,
			WIN_WIDTH, WIN_HEIGHT, "Playground");
	if (mlx->window == NULL)
		return (FAILURE);
	mlx->draw_image.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->draw_image.img == NULL)
		return (FAILURE);
	mlx->draw_image.addr = mlx_get_data_addr(mlx->draw_image.img,
			&mlx->draw_image.bpp,
			&mlx->draw_image.llen, &mlx->draw_image.endian);
	if (mlx->draw_image.addr == NULL)
		return (FAILURE);
	mlx->player_image = NULL;
	mlx->wall_image = NULL;
	mlx->floor_image = NULL;
	return (SUCCESS);
}

static void	set_player_north(t_player *player, char c)
{
	player->dirx = 0;
	player->diry = -1;
	player->planex = 0.66;
	player->planey = 0;
}

void	set_player_south(t_player *player, char c)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = -0.66;
	player->planey = 0;
}
