/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:51:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/15 16:51:02 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

#include "./enums.h"
#include "./macros.h"
#include "./include.h"

/**
 * Map info structures
 */
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

typedef struct s_door
{
	int x;
	int y;
	bool is_open;
}		t_door;

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

typedef struct	s_player
{
	double posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_player;

typedef struct s_nfo
{
	char		*north_textures_file;
	char		*south_textures_file;
	char		*west_textures_file;
	char		*east_textures_file;
	int			floor_colors[COLORS_SIZE];
	int			ceiling_colors[COLORS_SIZE];
	char		**map;
	int			map_width;
	int			map_height;
	t_door		*door;
	int			n_doors;
	t_player	*player;
}	t_info;

/**
 * Mlx-Image and attributes code structures
 */
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
	t_mlx_img	draw_image;
	void		*wall_image;
	void		*door_image;
	void		*floor_image;
	void		*player_image;
}	t_mlx;

/**
 * Full Program strcture, holding data for
 * both the map and the mlx information.
 */
typedef struct s_prog
{
	t_mlx	*mlx;
	t_info	*info;
}	t_prog;



#endif
