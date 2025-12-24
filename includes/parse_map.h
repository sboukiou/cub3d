/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 06:28:38 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/14 17:08:20 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "./types.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "./macros.h"
# include "./utils.h"
# include "./textures.h"
# include "./include.h"

int		empty_line(char *str, int *i);
void	get_player_position(char **map, double *player_x,
			double *player_y, char *c);
bool	file_name(char *path, char *str);
void	fill_struct_info(t_map_info *info, t_info **final_info);
int		count_lines(int *fd, char *file_name);
int		fill_map(char ***map, char *file_name);
char	**fill_map_arr(char **map, int j);
int		pars_element(t_element *element, t_map_info **info);
int		is_valid_map(char **map, t_map_info **info, t_map *map_info);
int		pars_line(char *line, int flag, t_map *map, char **arr);
void	fill_map_structure(t_map *map);
int		check_position(char c, t_map *map);
int		first_line(char *line, int flag);
int		last_letter(char *line, int i);
int		valid_element(char **map, t_map *map_info, int *i, t_element **element);
int		pars_lines(char **map, t_map *map_info, int *i);

#endif
