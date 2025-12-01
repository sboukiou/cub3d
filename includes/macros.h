/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:02:40 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/12 16:11:47 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

# define COLORS_SIZE 3
# define SUCCESS 0
#define FAILURE 1
# define MAP_SIZE 1024
# define MINIMAP_SIZE_SCALE 10
# define TRUE 1
# define KEY_E 101
# define FALSE 0
# define FAIL -1
# define ESCAPE 65307
/*Defining Window demensions*/
# define WIN_HEIGHT 576
# define WIN_WIDTH 1080
/*Defining Macros for events*/
# define KEY_PRESS_EVENT 2
# define BTN_PRESS_EVENT 4
# define DESTROY_NOTIFY_EVENT 17
# define PI 3.14159
# define ROT_SPEED 0.05
# define BLOCK_SIZE 22

/*Error Messages Macor-Definitions*/
# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

# define LT_NORTH  0
# define LT_SOUTH  1
# define LT_WEST   2
# define LT_EAST   3
# define LT_DOOR   4
# define LT_COUNT  5

# define UNUSED(X) (void)(X);
# define PANIC(X) dprintf(STDERR_FILENO, "Err: [%s]\n", X),\
	exit(EXIT_FAILURE);

#endif
