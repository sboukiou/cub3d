#ifndef MLX_EVENTS
# define MLX_EVENTS

#include "./types.h"

int		handle_key_press(int key_code, t_prog *prog);
int		handle_key_release(int key_code, t_prog *prog);
void	move_player(t_prog *prog);
void	destroy_program(t_prog *prog);
int		ft_exit(t_mlx *mlx);

#endif
