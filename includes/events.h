/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:02:27 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:02:45 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "./types.h"

int		handle_key_press(int key_code, t_prog *prog);
int		handle_key_release(int key_code, t_prog *prog);
void	move_player(t_prog *prog);
void	destroy_program(t_prog *prog);
int		ft_exit(t_mlx *mlx);

#endif
