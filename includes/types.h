/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 04:04:34 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/01 04:10:38 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H


# define COLORS_SIZE 3

typedef struct s_info
{
	char	*north_textures_file;
	char	*south_textures_file;
	char	*west_textures_file;
	char	*east_textures_file;
	int		floor_colors[COLORS_SIZE];
	int		ceiling_colors[COLORS_SIZE];
	char	**map;
	int		player_x;
	int		player_y;
}	t_info;

#endif
