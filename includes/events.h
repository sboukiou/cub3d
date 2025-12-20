/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:02:27 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/11 08:25:36 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "./types.h"

int		handle_key_press(int key_code, t_prog *prog);
int		handle_key_release(int key_code, t_prog *prog);
void	move_player(t_prog *prog);
void	destroy_program(t_prog *prog);
int     close_window(t_prog *prog);
int		ft_exit(t_mlx *mlx);
int		mouse_move(int x, int y, t_prog *prog);
int		mouse_hide(int button, int x, int y, t_prog *prog);
void	rotate_player(t_player *player, double angle);
void	handle_key_w(t_prog *prog);
void	handle_key_a(t_prog *prog);
void	handle_key_s(t_prog *prog);
void	handle_key_d(t_prog *prog);

#endif
