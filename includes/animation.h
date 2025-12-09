/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:44:06 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 16:44:07 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "types.h"

int	    load_animation(t_prog *prog, t_anim *anim, int frame_count, char *path);
void	render_animation(t_prog *prog, int x, int y, int flag);
void	free_animation(t_anim *anim, void *display);
#endif
