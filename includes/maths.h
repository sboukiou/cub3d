/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:07:10 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:07:20 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "types.h"

int				calculate_distance(int px, int py, int dx, int dy);
unsigned int	rgb_merge(int r, int g, int b);
void			calculateVertLine(t_prog *prog);
void			performeDDA(t_prog *prog);
void			settingSteps(t_prog *prog);
void			calculateRayPostion(t_prog *prog, int currentColumn);

#endif
