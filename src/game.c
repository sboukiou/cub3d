/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:30:58 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 20:31:53 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/events.h"
#include "../includes/types.h"
#include <mlx.h>
#include "../includes/checkers.h"
#include "../includes/draw.h"

int	game_layout(t_prog *prog)
{
	t_mlx	*mlx;
	t_info	*info;

	if (is_prog_valid(prog) == false)
		return (FAILURE);
	mlx = prog->mlx;
	info = prog->info;
	move_player(prog);
	if (mlx->draw_image.img != NULL)
		mlx_destroy_image(mlx->display, mlx->draw_image.img);
	mlx->draw_image.img = mlx_new_image(mlx->display, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->draw_image.img == NULL)
		return (FAILURE);
	mlx->draw_image.addr = mlx_get_data_addr(mlx->draw_image.img,
			&mlx->draw_image.bpp,
			&mlx->draw_image.llen, &mlx->draw_image.endian);
	render(prog);
	mlx_put_image_to_window(mlx->display, mlx->window,
		mlx->draw_image.img, 0, 0);
	return (SUCCESS);
}

bool	mlx_simulate_game(t_prog *prog)
{
	t_mlx	*mlx;
	t_info	*info;

	if (prog == NULL)
		return (false);
	mlx = prog->mlx;
	info = prog->info;
	game_layout(prog);
	mlx_hook(mlx->window, 2, 1L << 0, handle_key_press, prog);
	mlx_hook(mlx->window, 3, 1L << 1, handle_key_release, prog);
	mlx_loop_hook(mlx->display, game_layout, prog);
	mlx_hook(prog->mlx->window, 6, 1L << 6, mouse_move, prog);
	mlx_loop(prog->mlx->display);
	return (true);
}
