/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:51:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/08 17:17:57 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "./enums.h"
# include "./macros.h"
# include "./include.h"

/**
 * Map info structures
 */
typedef struct s_map
{
	bool	player;
	bool	so;
	bool	no;
	bool	ea;
	bool	we;
	bool	f;
	bool	c;
	int		i;
	int		map_index;
}				t_map;

typedef struct s_element
{
	char				*content;
	t_type				type;
	struct s_element	*next;
}				t_element;

typedef struct s_map_info
{
	t_element	*element;
	int			floor[COLORS_SIZE];
	int			ceiling[COLORS_SIZE];
	char		**map;
}				t_map_info;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_player;

typedef struct s_tex
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		llen;
	int		endian;
	char	*path;
}	t_tex;

typedef struct s_anim
{
	t_tex	*frames;
	int		frame_count;
	int		current_frame;
	int		delay_counter;
}	t_anim;

typedef struct s_nfo
{
	char		*north_textures_file;
	char		*south_textures_file;
	char		*west_textures_file;
	char		*east_textures_file;
	char		*door_textures_file;
	int			floor_colors[COLORS_SIZE];
	int			ceiling_colors[COLORS_SIZE];
	t_tex		texs[TEX_COUNT];
	char		**map;
	int			map_width;
	int			map_height;
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

typedef struct s_assets
{
	double			camerax;
	double			ray_dirx;
	double			ray_diry;
	int				mapx;
	int				mapy;
	double			side_distx;
	double			side_disty;
	double			delta_distx;
	double			delta_disty;
	double			perp_wall_dist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_idx;
	int				tex;
	int				tey;
	double			step;
	double			tex_pos;
	unsigned int	color;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_assets;

/**
 * Full Program strcture, holding data for
 * both the map and the mlx information.
 */
typedef struct s_prog
{
	t_mlx		*mlx;
	t_info		*info;
	t_assets	*assets;
	t_player	*player;
	t_anim		stand_anim;
	t_anim		attack_anim;
	t_anim		run_anim;
	bool		is_attacking;
	bool		is_running;
	bool		keys[65536];
}	t_prog;

typedef struct s_line
{
	int	draw_start;
	int	draw_end;
	int	color;
}	t_line;

#endif
