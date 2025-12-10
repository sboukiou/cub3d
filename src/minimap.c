/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:20:50 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/10 23:22:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <strings.h>
#include "../includes/draw.h"
#include "../includes/types.h"
#include "../includes/checkers.h"

static void	loop_draw(t_info *info, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '1')
				mlx_draw_square(mlx, j * 7, i * 7, 7);
			else if (info->map[i][j] != '0')
				mlx_draw_square(mlx, ((int)info->player->posx) * 7,
					(int)info->player->posy * 7, 7);
			j += 1;
		}
		i += 1;
	}
}

int	mini_map(t_prog *prog)
{
	t_info		*info;
	t_mlx		*mlx;
	t_assets	*assets;

	if (is_prog_valid(prog) == false)
		return (FAILURE);
	info = prog->info;
	mlx = prog->mlx;
	assets = prog->assets;
	loop_draw(info, mlx);
	return (SUCCESS);
}
