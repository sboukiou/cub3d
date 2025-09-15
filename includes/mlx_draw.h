#ifndef MLX_DRAW_H
# define MLX_DRAW_H

#include "./types.h"

int mlx_draw_minimap(t_mlx *mlx, t_info *info);
bool	mlx_draw_field(t_mlx *mlx, t_info *info);
bool	mlx_draw_square(t_mlx *mlx, int x, int y, int color, int size);

#endif
