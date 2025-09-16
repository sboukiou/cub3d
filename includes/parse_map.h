/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 06:28:38 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/12 16:31:00 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_C
#define PARSE_MAP_C

#include "./types.h"
#include "../lib/libft/libft.h"
#include "../lib/libft/get_next_line.h"
#include "./macros.h"
#include "./utils.h"
#include "./textures.h"
#include "./include.h"


t_door      *creat_doors(char **map, int *n_d);
void        get_player_position(char **map, int *player_x, int *player_y);
bool        file_name(char *str);
void        fill_struct_info(t_map_info *info, t_info **final_info); 
int         count_lines(int *fd, char *file_name);
int         fill_map(char ***map, char *file_name);
char        **fill_map_arr(char **map, int j);
int         pars_element(t_element *element, t_map_info **info);
int         is_valid_map(char **map, t_map_info **info, t_map *map_info);
int         pars_line(char *line, int flag, t_map *map, char **arr);
void        fill_map_structure(t_map *map);
int         check_position(char c, t_map *map);
int         first_line(char *line, int flag);
int	        last_letter(char *line, int i);
int	        valid_element(char **map, t_map *map_info, int *i, t_element **element);
int	        pars_lines(char **map, t_map *map_info, int *i);


#endif