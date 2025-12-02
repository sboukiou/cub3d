#include <stdbool.h>
#include <strings.h>
#include "../includes/draw.h"
#include "../includes/types.h"
#include "../includes/checkers.h"

int	miniMap(t_prog *prog)
{
	t_info		*info;
	t_mlx		*mlx;
	t_assets	*assets;

	if (isProgValid(prog) == false)
		return (FAILURE);
	info = prog->info;
	mlx = prog->mlx;
	assets = prog->assets;
	for (int i = 0; info->map[i]; i += 1)
		for (int j = 0; info->map[i][j]; j += 1)
		{
			if (info->map[i][j] == '1')
				mlx_draw_square(mlx, j * 7, i * 7, 0XFFFFF0, 7);
				/*put_pixel(mlx, j + 10, i + 10, 0XFFFFF0);*/
			else if (info->map[i][j] != '0')
				mlx_draw_square(mlx, ((int)info->player->posX) * 7, (int)info->player->posY * 7, 0X097969, 7);
		}

	return (SUCCESS);
}

