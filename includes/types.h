/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 04:04:34 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 18:00:14 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

# define COLORS_SIZE 3
#include "./enums.h"
#include "./macros.h"
#include "./include.h"

typedef struct s_map
{
	bool player;
	bool so;
	bool no;
	bool ea;
	bool we;
	bool f;
	bool c;
	int i;
	int map_index;
}				t_map;

typedef struct s_element
{
	char *content;
	t_type type;
	struct s_element *next;
}				t_element;

typedef struct s_map_info
{
	t_element	*element;
	int 		floor[COLORS_SIZE];
	int 		ceiling[COLORS_SIZE];
	char 		**map;
}				t_map_info;

typedef struct s_nfo
{
	char	*north_textures_file;
	char	*south_textures_file;
	char	*west_textures_file;
	char	*east_textures_file;
	int		floor_colors[COLORS_SIZE];
	int		ceiling_colors[COLORS_SIZE];
	int		**map;
	int		player_x;
	int		player_y;
	int	map_width;
	int	map_height;
}	t_info;

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx
{
	void		*display;
	void		*window;
	t_mlx_img	img;
}	t_mlx;

typedef struct s_prog
{
	t_mlx	*mlx;
	t_info	*info;
}	t_prog;

#endif
