#ifndef MLX_CRAETE_H
# define MLX_CRAETE_H

#include "./types.h"

void	mlx_create_small_playground(void *mlx, int map_width, int map_height);
int mlx_init_display(t_mlx *mlx);
void	buffered_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
void draw_player(int pos_x, int pos_y, t_mlx_img *img, t_info *info);
void draw_wall(int pos_x, int pos_y, t_mlx_img *img, int color, t_info *info);
#endif /* MLX_CRAETE_H */
