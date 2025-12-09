/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:45:50 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:02:05 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "./types.h"

int		mlx_draw_minimap(t_mlx *mlx, t_info *info);
bool	mlx_draw_field(t_mlx *mlx, t_info *info);
bool	mlx_draw_square(t_mlx *mlx, int x, int y, int size);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		draw_vert_line(t_mlx *mlx, int x, t_line line);
int		render(t_prog *prog);
void	cast_ray(t_prog *prog);

#endif
