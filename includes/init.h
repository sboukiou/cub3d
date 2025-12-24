/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:04:04 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 23:55:09 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "./types.h"

int		mlx_init_display(t_mlx *mlx);
int		init(t_info **info, t_player *player);

#endif /* INIT_H */
