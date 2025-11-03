#ifndef MLX_DRAW_H
# define MLX_DRAW_H

#include "./types.h"

int mlx_draw_minimap(t_mlx *mlx, t_info *info);
bool	mlx_draw_field(t_mlx *mlx, t_info *info);
bool	mlx_draw_square(t_mlx *mlx, int x, int y, int color, int size);
int	draw_line(t_mlx *mlx, t_info *info, int x, int y, double dx, double dy, int color);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int	draw_vert_line(t_mlx *mlx, int x, int drawStart, int drawEnd, int color);
int render(t_prog *prog);
#endif
