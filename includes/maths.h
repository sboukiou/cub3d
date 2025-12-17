/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:07:10 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 23:38:16 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "types.h"

int				calculate_distance(int px, int py, int dx, int dy);
unsigned int	rgb_merge(int r, int g, int b);
void			calculate_vert_line(t_prog *prog);
void			performe_dda(t_prog *prog);
void			setting_steps(t_prog *prog);
void			calculate_ray_postion(t_prog *prog, int currentColumn);
bool			in_range(float num, int val);

#endif
