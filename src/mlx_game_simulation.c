#include "../includes/mlx_events.h"
#include "../includes/types.h"
#include "../includes/mlx_draw.h"
#include "../lib/mlx_linux/mlx.h"


bool	mlx_simulate_game(t_prog *prog)
{
	t_mlx	*mlx;
	t_info	*info;

	if (prog == NULL)
		return (false);
	mlx = prog->mlx;
	info = prog->info;
	mlx_draw_minimap(mlx, info);
	mlx_draw_field(mlx, info);
	mlx_hook(mlx->window, 2, 1L<<0, handle_key, prog);
	/*Looping the game window*/
	mlx_loop(prog->mlx->display);
	return (true);
}
