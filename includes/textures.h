/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 06:25:03 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 18:00:14 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
#define TEXTURES_H

#include "./types.h"
#include "../lib/libft/libft.h"
#include "./utils.h"
#include "./macros.h"
#include "./include.h"

int	track_textures(char *line, int *flag, t_map *map_info, t_element **element);
int	north_texture(char *line, int *flag, t_map *map_info, t_element **element);
int	west_texture(char *line, int *flag, t_map *map_info, t_element **element);
int south_texture(char *line, int *flag, t_map *map_info, t_element **element);
int	east_texture(char *line, int *flag, t_map *map_info, t_element **element);
int	pars_floor_colors(t_map_info **info, char *str);
int	pars_ceiling_colors(t_map_info **info, char *str);
int	floor_color(char *line, int *flag, t_map *map_info, t_element **element);
int	check_path(char *str, char **path);
int	ceiling_color(char *line, int *flag, t_map *map_info, t_element **element);

#endif