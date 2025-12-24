/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:44:39 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 17:13:16 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"
#include "../includes/macros.h"
#include "../includes/draw.h"
#include "../includes/textures.h"
#include "../lib/libft/libft.h"
#include <mlx.h>

static char	*build_path(char *path, int i, char *xpm)
{
	char	*num_str;
	char	*temp;
	char	*full_path;

	num_str = ft_itoa(i + 1);
	temp = ft_strjoin(path, num_str);
	full_path = ft_strjoin(temp, xpm);
	return (full_path);
}

static void	update_animation(t_anim *anim)
{
	anim->delay_counter++;
	if (anim->delay_counter >= ANIM_DELAY)
	{
		anim->delay_counter = 0;
		anim->current_frame++;
		if (anim->current_frame >= anim->frame_count)
			anim->current_frame = 0;
	}
}

int	load_animation(t_prog *prog, t_anim *anim, int frame_count, char *path)
{
	int		w;
	int		h;
	int		i;

	anim->frame_count = frame_count;
	anim->current_frame = 0;
	anim->delay_counter = 0;
	anim->frames = ft_malloc(sizeof(t_tex) * frame_count, 1);
	if (!anim->frames)
		return (FAILURE);
	i = 0;
	while (i < frame_count)
	{
		anim->frames[i].img = mlx_xpm_file_to_image(prog->mlx->display,
				build_path(path, i, ".xpm"), &w, &h);
		if (!anim->frames[i].img)
			return (printf("Error\n%s %d\n", ERR_LOAD_ANIM, i + 1), FAILURE);
		anim->frames[i].data = mlx_get_data_addr(
				anim->frames[i].img, &anim->frames[i].bpp,
				&anim->frames[i].llen, &anim->frames[i].endian);
		anim->frames[i].width = w;
		anim->frames[i].height = h;
		i++;
	}
	return (SUCCESS);
}

void	render_animation(t_prog *prog, int x, int y, int flag)
{
	t_anim			*anim;
	t_tex			*frame;
	int				dest_x;
	int				dest_y;
	unsigned int	color;

	if (flag == ATTACK)
		anim = &prog->attack_anim;
	else if (flag == RUN)
		anim = &prog->run_anim;
	else
		anim = &prog->stand_anim;
	frame = &anim->frames[anim->current_frame];
	dest_x = (WIN_WIDTH - frame->width) / 2;
	dest_y = WIN_HEIGHT - frame->height;
	while (++y < frame->height)
	{
		x = -1;
		while (++x < frame->width)
		{
			color = textures_get_pixel(frame, x, y);
			draw_pixel_scaled(prog->mlx, dest_x + x, dest_y + y, color);
		}
	}
	update_animation(anim);
}

void	free_animation(t_anim *anim, void *display)
{
	int	i;

	if (!anim || !anim->frames || !display)
		return ;
	i = 0;
	while (i < anim->frame_count)
	{
		if (!anim->frames[i].img)
			break ;
		mlx_destroy_image(display, anim->frames[i].img);
		i++;
	}
	anim->frames = NULL;
}
