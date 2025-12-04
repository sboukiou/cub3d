#ifndef ANIMATION_H
# define ANIMATION_H

# include "types.h"

int	    load_animation(t_prog *prog, t_anim *anim, int frame_count, char *path);
void	render_animation(t_prog *prog, int x, int y, int flag);
void	free_animation(t_anim *anim, void *display);

#endif
