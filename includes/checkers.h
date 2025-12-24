/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:44:25 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/11 00:22:51 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_H
# define CHECKERS_H

# include "types.h"

bool	is_prog_valid(t_prog *prog);
void	print_controllers(void);
void	handle_player_direction(t_player *player, char c);
int		init_prog_data(t_prog **prog, char **av);

#endif
