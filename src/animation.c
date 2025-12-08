/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:44:39 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:44:40 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"
#include "../includes/macros.h"
#include "../includes/draw.h"
#include "../includes/textures.h"
#include <mlx.h>

int	load_stand_animation(t_prog *prog)
{
	t_mlx	*mlx;
	int		w;
	int		h;

	mlx = prog->mlx;
	prog->stand_anim.frame_count = STAND_FRAMES;
	prog->stand_anim.current_frame = 0;
	prog->stand_anim.delay_counter = 0;
	prog->stand_anim.frames = malloc(sizeof(t_tex) * STAND_FRAMES);
	if (!prog->stand_anim.frames)
		return (FAILURE);
	
	// Load the standing pose texture
	prog->stand_anim.frames[0].img = mlx_xpm_file_to_image(mlx->display,
		"textures/stand/pose.xpm", &w, &h);
	if (!prog->stand_anim.frames[0].img)
	{
		printf("Error: Could not load stand animation frame\n");
		return (FAILURE);
	}
	prog->stand_anim.frames[0].data = mlx_get_data_addr(
		prog->stand_anim.frames[0].img,
		&prog->stand_anim.frames[0].bpp,
		&prog->stand_anim.frames[0].llen,
		&prog->stand_anim.frames[0].endian);
	prog->stand_anim.frames[0].width = w;
	prog->stand_anim.frames[0].height = h;
	return (SUCCESS);
}

char *build_path(char *path, int i, char *xpm)
{
	char *num_str;
	char *temp;
	char *full_path;

	num_str = ft_itoa(i + 1);
	temp = ft_strjoin(path, num_str);
	full_path = ft_strjoin(temp, xpm);
	free(num_str);
	free(temp);
	return full_path;
}
int	load_attack_animation(t_prog *prog)
{
	t_mlx	*mlx;
	int		w;
	int		h;
	int		i;

	mlx = prog->mlx;
	prog->attack_anim.frame_count = ATTACK_FRAMES;
	prog->attack_anim.delay_counter = 0;
	prog->attack_anim.frames = malloc(sizeof(t_tex) * ATTACK_FRAMES);
	if (!prog->attack_anim.frames)
		return (FAILURE);
	
	i = 0;
	while (i < ATTACK_FRAMES)
	{
		prog->attack_anim.current_frame = i;
		prog->attack_anim.frames[i].img = mlx_xpm_file_to_image(mlx->display,
				build_path("textures/attack/", i, ".xpm"), &w, &h);
		if (!prog->attack_anim.frames[i].img)
		{
			printf("Error: Could not load attack animation frame %d\n", i + 1);
			return (FAILURE);
		}
		prog->attack_anim.frames[i].data = mlx_get_data_addr(
				prog->attack_anim.frames[i].img,
				&prog->attack_anim.frames[i].bpp,
				&prog->attack_anim.frames[i].llen,
				&prog->attack_anim.frames[i].endian);
		prog->attack_anim.frames[i].width = w;
		prog->attack_anim.frames[i].height = h;
		i++;
	}
	return (SUCCESS);
}

int	load_run_animation(t_prog *prog)
{
	t_mlx	*mlx;
	int		w;
	int		h;
	int		i;
	char	*path;

	mlx = prog->mlx;
	prog->run_anim.frame_count = RUN_FRAMES;
	prog->run_anim.current_frame = 0;
	prog->run_anim.delay_counter = 0;
	prog->run_anim.frames = malloc(sizeof(t_tex) * RUN_FRAMES);
	if (!prog->run_anim.frames)
		return (FAILURE);
	i = 0;
	while (i < RUN_FRAMES)
	{
		path = build_path("textures/run/", i, ".xpm");
		prog->run_anim.frames[i].img = mlx_xpm_file_to_image(mlx->display,
				path, &w, &h);
		free(path);
		if (!prog->run_anim.frames[i].img)
		{
			printf("Error: Could not load run animation frame %d\n", i + 1);
			return (FAILURE);
		}
		prog->run_anim.frames[i].data = mlx_get_data_addr(
				prog->run_anim.frames[i].img,
				&prog->run_anim.frames[i].bpp,
				&prog->run_anim.frames[i].llen,
				&prog->run_anim.frames[i].endian);
		prog->run_anim.frames[i].width = w;
		prog->run_anim.frames[i].height = h;
		i++;
	}
	return (SUCCESS);
}

void	update_animation(t_anim *anim)
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

static void	draw_pixel_scaled(t_mlx *mlx, int x, int y, unsigned int color)
{
	if (color == 0xFF000000 || (color & 0xFF000000))
		return ;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		put_pixel(mlx, x, y, color);
}

void	render_animation(t_prog *prog, int x, int y, int flag)
{
	t_anim		*anim;
	t_tex		*frame;
	int			dest_x;
	int			dest_y;
	unsigned int color;

	if (flag == ATTACK)
		anim = &prog->attack_anim;
	else if (flag == RUN)
		anim = &prog->run_anim;
	else
		anim = &prog->stand_anim;
	frame = &anim->frames[anim->current_frame];
	dest_x = (WIN_WIDTH - frame->width) / 2;
	dest_y = WIN_HEIGHT - frame->height;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			color = textures_get_pixel(frame, x, y);
			draw_pixel_scaled(prog->mlx, dest_x + x, dest_y + y, color);
			x++;
		}
		y++;
	}
	update_animation(anim);
}

void	free_animation(t_anim *anim, void *display)
{
	int	i;

	if (!anim->frames)
		return ;
	i = 0;
	while (i < anim->frame_count)
	{
		if (anim->frames[i].img)
			mlx_destroy_image(display, anim->frames[i].img);
		i++;
	}
	free(anim->frames);
	anim->frames = NULL;
}
