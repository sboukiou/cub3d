/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 04:09:48 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/01 04:10:24 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
#define

typedef struct e_textures
{
	T_SO,
	t_WE,
	T_EA,
	T_NO,
}				t_textures;

typedef struct e_colors
{
	C_FLOUR,
	C_CEILING,
}				t_colors;

typedef struct e_player_pos
{
	P_NO,
	P_SO,
	P_EA,
	P_WE,
}				t_player_pos;

#endif
